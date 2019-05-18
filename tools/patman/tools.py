# SPDX-License-Identifier: GPL-2.0+
#
# Copyright (c) 2016 Google, Inc
#

import command
import glob
import os
import shutil
import sys
import tempfile

import tout

# Output directly (generally this is temporary)
outdir = None

# True to keep the output directory around after exiting
preserve_outdir = False

# Path to the Chrome OS chroot, if we know it
chroot_path = None

# Search paths to use for Filename(), used to find files
search_paths = []

# Tools and the packages that contain them, on debian
packages = {
    'lz4': 'liblz4-tool',
    }

# List of paths to use when looking for an input file
indir = []

def PrepareOutputDir(dirname, preserve=False):
    """Select an output directory, ensuring it exists.

    This either creates a temporary directory or checks that the one supplied
    by the user is valid. For a temporary directory, it makes a note to
    remove it later if required.

    Args:
        dirname: a string, name of the output directory to use to store
                intermediate and output files. If is None - create a temporary
                directory.
        preserve: a Boolean. If outdir above is None and preserve is False, the
                created temporary directory will be destroyed on exit.

    Raises:
        OSError: If it cannot create the output directory.
    """
    global outdir, preserve_outdir

    preserve_outdir = dirname or preserve
    if dirname:
        outdir = dirname
        if not os.path.isdir(outdir):
            try:
                os.makedirs(outdir)
            except OSError as err:
                raise CmdError("Cannot make output directory '%s': '%s'" %
                                (outdir, err.strerror))
        tout.Debug("Using output directory '%s'" % outdir)
    else:
        outdir = tempfile.mkdtemp(prefix='binman.')
        tout.Debug("Using temporary directory '%s'" % outdir)

def _RemoveOutputDir():
    global outdir

    shutil.rmtree(outdir)
    tout.Debug("Deleted temporary directory '%s'" % outdir)
    outdir = None

def FinaliseOutputDir():
    global outdir, preserve_outdir

    """Tidy up: delete output directory if temporary and not preserved."""
    if outdir and not preserve_outdir:
        _RemoveOutputDir()

def GetOutputFilename(fname):
    """Return a filename within the output directory.

    Args:
        fname: Filename to use for new file

    Returns:
        The full path of the filename, within the output directory
    """
    return os.path.join(outdir, fname)

def _FinaliseForTest():
    """Remove the output directory (for use by tests)"""
    global outdir

    if outdir:
        _RemoveOutputDir()

def SetInputDirs(dirname):
    """Add a list of input directories, where input files are kept.

    Args:
        dirname: a list of paths to input directories to use for obtaining
                files needed by binman to place in the image.
    """
    global indir

    indir = dirname
    tout.Debug("Using input directories %s" % indir)

def GetInputFilename(fname):
    """Return a filename for use as input.

    Args:
        fname: Filename to use for new file

    Returns:
        The full path of the filename, within the input directory
    """
    if not indir:
        return fname
    for dirname in indir:
        pathname = os.path.join(dirname, fname)
        if os.path.exists(pathname):
            return pathname

    raise ValueError("Filename '%s' not found in input path (%s) (cwd='%s')" %
                     (fname, ','.join(indir), os.getcwd()))

def GetInputFilenameGlob(pattern):
    """Return a list of filenames for use as input.

    Args:
        pattern: Filename pattern to search for

    Returns:
        A list of matching files in all input directories
    """
    if not indir:
        return glob.glob(fname)
    files = []
    for dirname in indir:
        pathname = os.path.join(dirname, pattern)
        files += glob.glob(pathname)
    return sorted(files)

def Align(pos, align):
    if align:
        mask = align - 1
        pos = (pos + mask) & ~mask
    return pos

def NotPowerOfTwo(num):
    return num and (num & (num - 1))

def PathHasFile(fname):
    """Check if a given filename is in the PATH

    Args:
        fname: Filename to check

    Returns:
        True if found, False if not
    """
    for dir in os.environ['PATH'].split(':'):
        if os.path.exists(os.path.join(dir, fname)):
            return True
    return False

def Run(name, *args, **kwargs):
    try:
        return command.Run(name, *args, cwd=outdir, capture=True, **kwargs)
    except:
        if not PathHasFile(name):
            msg = "Plesae install tool '%s'" % name
            package = packages.get(name)
            if package:
                 msg += " (e.g. from package '%s')" % package
            raise ValueError(msg)
        raise

def Filename(fname):
    """Resolve a file path to an absolute path.

    If fname starts with ##/ and chroot is available, ##/ gets replaced with
    the chroot path. If chroot is not available, this file name can not be
    resolved, `None' is returned.

    If fname is not prepended with the above prefix, and is not an existing
    file, the actual file name is retrieved from the passed in string and the
    search_paths directories (if any) are searched to for the file. If found -
    the path to the found file is returned, `None' is returned otherwise.

    Args:
      fname: a string,  the path to resolve.

    Returns:
      Absolute path to the file or None if not found.
    """
    if fname.startswith('##/'):
      if chroot_path:
        fname = os.path.join(chroot_path, fname[3:])
      else:
        return None

    # Search for a pathname that exists, and return it if found
    if fname and not os.path.exists(fname):
        for path in search_paths:
            pathname = os.path.join(path, os.path.basename(fname))
            if os.path.exists(pathname):
                return pathname

    # If not found, just return the standard, unchanged path
    return fname

def ReadFile(fname):
    """Read and return the contents of a file.

    Args:
      fname: path to filename to read, where ## signifiies the chroot.

    Returns:
      data read from file, as a string.
    """
    with open(Filename(fname), 'rb') as fd:
        data = fd.read()
    #self._out.Info("Read file '%s' size %d (%#0x)" %
                   #(fname, len(data), len(data)))
    return data

def WriteFile(fname, data):
    """Write data into a file.

    Args:
        fname: path to filename to write
        data: data to write to file, as a string
    """
    #self._out.Info("Write file '%s' size %d (%#0x)" %
                   #(fname, len(data), len(data)))
    with open(Filename(fname), 'wb') as fd:
        fd.write(data)

def GetBytes(byte, size):
    """Get a string of bytes of a given size

    This handles the unfortunate different between Python 2 and Python 2.

    Args:
        byte: Numeric byte value to use
        size: Size of bytes/string to return

    Returns:
        A bytes type with 'byte' repeated 'size' times
    """
    if sys.version_info[0] >= 3:
        data = bytes([byte]) * size
    else:
        data = chr(byte) * size
    return data

def ToUnicode(val):
    """Make sure a value is a unicode string

    This allows some amount of compatibility between Python 2 and Python3. For
    the former, it returns a unicode object.

    Args:
        val: string or unicode object

    Returns:
        unicode version of val
    """
    if sys.version_info[0] >= 3:
        return val
    return val if isinstance(val, unicode) else val.decode('utf-8')

def FromUnicode(val):
    """Make sure a value is a non-unicode string

    This allows some amount of compatibility between Python 2 and Python3. For
    the former, it converts a unicode object to a string.

    Args:
        val: string or unicode object

    Returns:
        non-unicode version of val
    """
    if sys.version_info[0] >= 3:
        return val
    return val if isinstance(val, str) else val.encode('utf-8')

def ToByte(ch):
    """Convert a character to an ASCII value

    This is useful because in Python 2 bytes is an alias for str, but in
    Python 3 they are separate types. This function converts the argument to
    an ASCII value in either case.

    Args:
        ch: A string (Python 2) or byte (Python 3) value

    Returns:
        integer ASCII value for ch
    """
    return ord(ch) if type(ch) == str else ch

def ToChar(byte):
    """Convert a byte to a character

    This is useful because in Python 2 bytes is an alias for str, but in
    Python 3 they are separate types. This function converts an ASCII value to
    a value with the appropriate type in either case.

    Args:
        byte: A byte or str value
    """
    return chr(byte) if type(byte) != str else byte

def ToChars(byte_list):
    """Convert a list of bytes to a str/bytes type

    Args:
        byte_list: List of ASCII values representing the string

    Returns:
        string made by concatenating all the ASCII values
    """
    return ''.join([chr(byte) for byte in byte_list])

def ToBytes(string):
    """Convert a str type into a bytes type

    Args:
        string: string to convert value

    Returns:
        Python 3: A bytes type
        Python 2: A string type
    """
    if sys.version_info[0] >= 3:
        return string.encode('utf-8')
    return string
