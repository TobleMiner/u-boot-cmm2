# SPDX-License-Identifier: GPL-2.0+
# Copyright (c) 2018 Google, Inc
# Written by Simon Glass <sjg@chromium.org>
#
# Entry-type module for U-Boot device tree files
#

import state

from entry import Entry
from blob import Entry_blob

class Entry_blob_dtb(Entry_blob):
    """A blob that holds a device tree

    This is a blob containing a device tree. The contents of the blob are
    obtained from the list of available device-tree files, managed by the
    'state' module.
    """
    def __init__(self, section, etype, node):
        Entry_blob.__init__(self, section, etype, node)

    def ObtainContents(self):
        """Get the device-tree from the list held by the 'state' module"""
        self._filename = self.GetDefaultFilename()
        self._pathname, _ = state.GetFdtContents(self._filename)
        return Entry_blob.ReadBlobContents(self)

    def ProcessContents(self):
        """Re-read the DTB contents so that we get any calculated properties"""
        _, indata = state.GetFdtContents(self._filename)
        data = self.CompressData(indata)
        return self.ProcessContentsUpdate(data)

    def GetFdtEtype(self):
        """Get the entry type of this device tree

        This can be 'u-boot-dtb', 'u-boot-spl-dtb' or 'u-boot-tpl-dtb'
        Returns:
            Entry type if any, e.g. 'u-boot-dtb'
        """
        return None

    def GetFdts(self):
        """Get the device trees used by this entry

        Returns:
            Dict:
                key: Filename from this entry (without the path)
                value: Tuple:
                    Fdt object for this dtb, or None if not available
                    Filename of file containing this dtb
        """
        fname = self.GetDefaultFilename()
        return {self.GetFdtEtype(): [self, fname]}
