/*
 *  EFI application disk support
 *
 *  Copyright (c) 2016 Alexander Graf
 *
 *  SPDX-License-Identifier:     GPL-2.0+
 */

#include <common.h>
#include <dm.h>
#include <efi_loader.h>
#include <inttypes.h>
#include <lcd.h>
#include <malloc.h>
#include <video.h>

DECLARE_GLOBAL_DATA_PTR;

static const efi_guid_t efi_gop_guid = EFI_GOP_GUID;

struct efi_gop_obj {
	/* Generic EFI object parent class data */
	struct efi_object parent;
	/* EFI Interface callback struct for gop */
	struct efi_gop ops;
	/* The only mode we support */
	struct efi_gop_mode_info info;
	struct efi_gop_mode mode;
	/* Fields we only have acces to during init */
	u32 bpix;
	void *fb;
};

static efi_status_t EFIAPI gop_query_mode(struct efi_gop *this, u32 mode_number,
					  efi_uintn_t *size_of_info,
					  struct efi_gop_mode_info **info)
{
	struct efi_gop_obj *gopobj;

	EFI_ENTRY("%p, %x, %p, %p", this, mode_number, size_of_info, info);

	gopobj = container_of(this, struct efi_gop_obj, ops);
	*size_of_info = sizeof(gopobj->info);
	*info = &gopobj->info;

	return EFI_EXIT(EFI_SUCCESS);
}

static efi_status_t EFIAPI gop_set_mode(struct efi_gop *this, u32 mode_number)
{
	EFI_ENTRY("%p, %x", this, mode_number);

	if (mode_number != 0)
		return EFI_EXIT(EFI_INVALID_PARAMETER);

	return EFI_EXIT(EFI_SUCCESS);
}

static __always_inline struct efi_gop_pixel efi_vid16_to_blt_col(u16 vid)
{
	struct efi_gop_pixel blt = {
		.reserved = 0,
	};

	blt.blue  = (vid & 0x1f) << 3;
	vid >>= 5;
	blt.green = (vid & 0x3f) << 2;
	vid >>= 6;
	blt.red   = (vid & 0x1f) << 3;
	return blt;
}

static __always_inline u16 efi_blt_col_to_vid16(struct efi_gop_pixel *blt)
{
	return (u16)(blt->red   >> 3) << 11 |
	       (u16)(blt->green >> 2) <<  5 |
	       (u16)(blt->blue  >> 3);
}

/*
 * Copy rectangle.
 *
 * This function implements the Blt service of the EFI_GRAPHICS_OUTPUT_PROTOCOL.
 * See the Unified Extensible Firmware Interface (UEFI) specification for
 * details.
 *
 * @this:	EFI_GRAPHICS_OUTPUT_PROTOCOL
 * @buffer:	pixel buffer
 * @sx:		source x-coordinate
 * @sy:		source y-coordinate
 * @dx:		destination x-coordinate
 * @dy:		destination y-coordinate
 * @width:	width of rectangle
 * @height:	height of rectangle
 * @delta:	length in bytes of a line in the pixel buffer (optional)
 * @return:	status code
 */
efi_status_t EFIAPI gop_blt(struct efi_gop *this, struct efi_gop_pixel *buffer,
			    u32 operation, efi_uintn_t sx,
			    efi_uintn_t sy, efi_uintn_t dx,
			    efi_uintn_t dy, efi_uintn_t width,
			    efi_uintn_t height, efi_uintn_t delta)
{
	struct efi_gop_obj *gopobj = container_of(this, struct efi_gop_obj, ops);
	efi_uintn_t i, j, linelen;
	u32 *fb32 = gopobj->fb;
	u16 *fb16 = gopobj->fb;

	EFI_ENTRY("%p, %p, %u, %zu, %zu, %zu, %zu, %zu, %zu, %zu", this,
		  buffer, operation, sx, sy, dx, dy, width, height, delta);

	if (delta) {
		/* Check for 4 byte alignment */
		if (delta & 3)
			return EFI_EXIT(EFI_INVALID_PARAMETER);
		linelen = delta >> 2;
	} else {
		linelen = width;
	}

	/* Check source rectangle */
	switch (operation) {
	case EFI_BLT_VIDEO_FILL:
		break;
	case EFI_BLT_BUFFER_TO_VIDEO:
		if (sx + width > linelen)
			return EFI_EXIT(EFI_INVALID_PARAMETER);
		break;
	case EFI_BLT_VIDEO_TO_BLT_BUFFER:
	case EFI_BLT_VIDEO_TO_VIDEO:
		if (sx + width > gopobj->info.width ||
		    sy + height > gopobj->info.height)
			return EFI_EXIT(EFI_INVALID_PARAMETER);
		break;
	default:
		return EFI_EXIT(EFI_INVALID_PARAMETER);
	}

	/* Check destination rectangle */
	switch (operation) {
	case EFI_BLT_VIDEO_FILL:
	case EFI_BLT_BUFFER_TO_VIDEO:
	case EFI_BLT_VIDEO_TO_VIDEO:
		if (dx + width > gopobj->info.width ||
		    dy + height > gopobj->info.height)
			return EFI_EXIT(EFI_INVALID_PARAMETER);
		break;
	case EFI_BLT_VIDEO_TO_BLT_BUFFER:
		if (dx + width > linelen)
			return EFI_EXIT(EFI_INVALID_PARAMETER);
		break;
	}

	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			struct efi_gop_pixel pix;

			/* Read source pixel */
			switch (operation) {
			case EFI_BLT_VIDEO_FILL:
				pix = *buffer;
				break;
			case EFI_BLT_BUFFER_TO_VIDEO:
				pix = buffer[linelen * (i + sy) + j + sx];
				break;
			case EFI_BLT_VIDEO_TO_BLT_BUFFER:
			case EFI_BLT_VIDEO_TO_VIDEO:
				switch (gopobj->bpix) {
#ifdef CONFIG_DM_VIDEO
				case VIDEO_BPP32:
#else
				case LCD_COLOR32:
#endif
					pix = *(struct efi_gop_pixel *)&fb32[
						gopobj->info.width *
						(i + sy) + j + sx];
				break;
#ifdef CONFIG_DM_VIDEO
				case VIDEO_BPP16:
#else
				case LCD_COLOR16:
#endif
					pix = efi_vid16_to_blt_col(fb16[
						gopobj->info.width *
						(i + sy) + j + sx]);
					break;
				default:
					return EFI_EXIT(EFI_UNSUPPORTED);
				}
				break;
			}

			/* Write destination pixel */
			switch (operation) {
			case EFI_BLT_VIDEO_TO_BLT_BUFFER:
				buffer[linelen * (i + dy) + j + dx] = pix;
				break;
			case EFI_BLT_BUFFER_TO_VIDEO:
			case EFI_BLT_VIDEO_FILL:
			case EFI_BLT_VIDEO_TO_VIDEO:
				switch (gopobj->bpix) {
#ifdef CONFIG_DM_VIDEO
				case VIDEO_BPP32:
#else
				case LCD_COLOR32:
#endif
					fb32[gopobj->info.width *
					     (i + dy) + j + dx] = *(u32 *)&pix;
					break;
#ifdef CONFIG_DM_VIDEO
				case VIDEO_BPP16:
#else
				case LCD_COLOR16:
#endif
					fb16[gopobj->info.width *
					     (i + dy) + j + dx] =
						efi_blt_col_to_vid16(&pix);
					break;
				default:
					return EFI_EXIT(EFI_UNSUPPORTED);
				}
				break;
			}
		}
	}

#ifdef CONFIG_DM_VIDEO
	video_sync_all();
#else
	lcd_sync();
#endif

	return EFI_EXIT(EFI_SUCCESS);
}

/*
 * Install graphical output protocol.
 *
 * If no supported video device exists this is not considered as an
 * error.
 */
efi_status_t efi_gop_register(void)
{
	struct efi_gop_obj *gopobj;
	u32 bpix, col, row;
	u64 fb_base, fb_size;
	void *fb;
	efi_status_t ret;

#ifdef CONFIG_DM_VIDEO
	struct udevice *vdev;
	struct video_priv *priv;

	/* We only support a single video output device for now */
	if (uclass_first_device(UCLASS_VIDEO, &vdev) || !vdev) {
		debug("WARNING: No video device\n");
		return EFI_SUCCESS;
	}

	priv = dev_get_uclass_priv(vdev);
	bpix = priv->bpix;
	col = video_get_xsize(vdev);
	row = video_get_ysize(vdev);
	fb_base = (uintptr_t)priv->fb;
	fb_size = priv->fb_size;
	fb = priv->fb;
#else
	int line_len;

	bpix = panel_info.vl_bpix;
	col = panel_info.vl_col;
	row = panel_info.vl_row;
	fb_base = gd->fb_base;
	fb_size = lcd_get_size(&line_len);
	fb = (void*)gd->fb_base;
#endif

	switch (bpix) {
#ifdef CONFIG_DM_VIDEO
	case VIDEO_BPP16:
	case VIDEO_BPP32:
#else
	case LCD_COLOR32:
	case LCD_COLOR16:
#endif
		break;
	default:
		/* So far, we only work in 16 or 32 bit mode */
		debug("WARNING: Unsupported video mode\n");
		return EFI_SUCCESS;
	}

	gopobj = calloc(1, sizeof(*gopobj));
	if (!gopobj) {
		printf("ERROR: Out of memory\n");
		return EFI_OUT_OF_RESOURCES;
	}

	/* Hook up to the device list */
	efi_add_handle(&gopobj->parent);

	/* Fill in object data */
	ret = efi_add_protocol(gopobj->parent.handle, &efi_gop_guid,
			       &gopobj->ops);
	if (ret != EFI_SUCCESS) {
		printf("ERROR: Failure adding gop protocol\n");
		return ret;
	}
	gopobj->ops.query_mode = gop_query_mode;
	gopobj->ops.set_mode = gop_set_mode;
	gopobj->ops.blt = gop_blt;
	gopobj->ops.mode = &gopobj->mode;

	gopobj->mode.max_mode = 1;
	gopobj->mode.info = &gopobj->info;
	gopobj->mode.info_size = sizeof(gopobj->info);

#ifdef CONFIG_DM_VIDEO
	if (bpix == VIDEO_BPP32)
#else
	if (bpix == LCD_COLOR32)
#endif
	{
		/* With 32bit color space we can directly expose the fb */
		gopobj->mode.fb_base = fb_base;
		gopobj->mode.fb_size = fb_size;
	}

	gopobj->info.version = 0;
	gopobj->info.width = col;
	gopobj->info.height = row;
	gopobj->info.pixel_format = EFI_GOT_RGBA8;
	gopobj->info.pixels_per_scanline = col;

	gopobj->bpix = bpix;
	gopobj->fb = fb;

	return EFI_SUCCESS;
}
