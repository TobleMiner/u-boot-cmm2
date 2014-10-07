/*
 * Copyright 2014 Freescale Semiconductor, Inc.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 *
 */

#ifndef __JOBDESC_H
#define __JOBDESC_H

#include <common.h>
#include <asm/io.h>

#define KEY_IDNFR_SZ_BYTES		16

void inline_cnstr_jobdesc_hash(uint32_t *desc,
			  const uint8_t *msg, uint32_t msgsz, uint8_t *digest,
			  u32 alg_type, uint32_t alg_size, int sg_tbl);

void inline_cnstr_jobdesc_blob_encap(uint32_t *desc, uint8_t *key_idnfr,
				     uint8_t *plain_txt, uint8_t *enc_blob,
				     uint32_t in_sz);

void inline_cnstr_jobdesc_blob_decap(uint32_t *desc, uint8_t *key_idnfr,
				     uint8_t *enc_blob, uint8_t *plain_txt,
				     uint32_t out_sz);

void inline_cnstr_jobdesc_rng_instantiation(uint32_t *desc);
#endif
