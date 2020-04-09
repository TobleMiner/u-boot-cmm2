# SPDX-License-Identifier: GPL-2.0+
# Copyright (c) 2012 The Chromium OS Authors.
#

import os
import shutil
import sys
import tempfile
import time
import unittest

# Bring in the patman libraries
our_path = os.path.dirname(os.path.realpath(__file__))
sys.path.append(os.path.join(our_path, '../patman'))

import board
import bsettings
import builder
import control
import command
import commit
import terminal
import test_util
import toolchain
import tools

use_network = True

settings_data = '''
# Buildman settings file

[toolchain]
main: /usr/sbin

[toolchain-alias]
x86: i386 x86_64
'''

errors = [
    '''main.c: In function 'main_loop':
main.c:260:6: warning: unused variable 'joe' [-Wunused-variable]
''',
    '''main.c: In function 'main_loop2':
main.c:295:2: error: 'fred' undeclared (first use in this function)
main.c:295:2: note: each undeclared identifier is reported only once for each function it appears in
make[1]: *** [main.o] Error 1
make: *** [common/libcommon.o] Error 2
Make failed
''',
    '''arch/arm/dts/socfpga_arria10_socdk_sdmmc.dtb: Warning \
(avoid_unnecessary_addr_size): /clocks: unnecessary #address-cells/#size-cells \
without "ranges" or child "reg" property
''',
    '''powerpc-linux-ld: warning: dot moved backwards before `.bss'
powerpc-linux-ld: warning: dot moved backwards before `.bss'
powerpc-linux-ld: u-boot: section .text lma 0xfffc0000 overlaps previous sections
powerpc-linux-ld: u-boot: section .rodata lma 0xfffef3ec overlaps previous sections
powerpc-linux-ld: u-boot: section .reloc lma 0xffffa400 overlaps previous sections
powerpc-linux-ld: u-boot: section .data lma 0xffffcd38 overlaps previous sections
powerpc-linux-ld: u-boot: section .u_boot_cmd lma 0xffffeb40 overlaps previous sections
powerpc-linux-ld: u-boot: section .bootpg lma 0xfffff198 overlaps previous sections
''',
   '''In file included from %(basedir)sarch/sandbox/cpu/cpu.c:9:0:
%(basedir)sarch/sandbox/include/asm/state.h:44:0: warning: "xxxx" redefined [enabled by default]
%(basedir)sarch/sandbox/include/asm/state.h:43:0: note: this is the location of the previous definition
%(basedir)sarch/sandbox/cpu/cpu.c: In function 'do_reset':
%(basedir)sarch/sandbox/cpu/cpu.c:27:1: error: unknown type name 'blah'
%(basedir)sarch/sandbox/cpu/cpu.c:28:12: error: expected declaration specifiers or '...' before numeric constant
make[2]: *** [arch/sandbox/cpu/cpu.o] Error 1
make[1]: *** [arch/sandbox/cpu] Error 2
make[1]: *** Waiting for unfinished jobs....
In file included from %(basedir)scommon/board_f.c:55:0:
%(basedir)sarch/sandbox/include/asm/state.h:44:0: warning: "xxxx" redefined [enabled by default]
%(basedir)sarch/sandbox/include/asm/state.h:43:0: note: this is the location of the previous definition
make: *** [sub-make] Error 2
'''
]


# hash, subject, return code, list of errors/warnings
commits = [
    ['1234', 'upstream/master, ok', 0, []],
    ['5678', 'Second commit, a warning', 0, errors[0:1]],
    ['9012', 'Third commit, error', 1, errors[0:2]],
    ['3456', 'Fourth commit, warning', 0, [errors[0], errors[2]]],
    ['7890', 'Fifth commit, link errors', 1, [errors[0], errors[3]]],
    ['abcd', 'Sixth commit, fixes all errors', 0, []],
    ['ef01', 'Seventh commit, check directory suppression', 1, [errors[4]]],
]

boards = [
    ['Active', 'arm', 'armv7', '', 'Tester', 'ARM Board 1', 'board0',  ''],
    ['Active', 'arm', 'armv7', '', 'Tester', 'ARM Board 2', 'board1', ''],
    ['Active', 'powerpc', 'powerpc', '', 'Tester', 'PowerPC board 1', 'board2', ''],
    ['Active', 'powerpc', 'mpc83xx', '', 'Tester', 'PowerPC board 2', 'board3', ''],
    ['Active', 'sandbox', 'sandbox', '', 'Tester', 'Sandbox board', 'board4', ''],
]

BASE_DIR = 'base'

OUTCOME_OK, OUTCOME_WARN, OUTCOME_ERR = range(3)

class Options:
    """Class that holds build options"""
    pass

class TestBuild(unittest.TestCase):
    """Test buildman

    TODO: Write tests for the rest of the functionality
    """
    def setUp(self):
        # Set up commits to build
        self.commits = []
        sequence = 0
        for commit_info in commits:
            comm = commit.Commit(commit_info[0])
            comm.subject = commit_info[1]
            comm.return_code = commit_info[2]
            comm.error_list = commit_info[3]
            comm.sequence = sequence
            sequence += 1
            self.commits.append(comm)

        # Set up boards to build
        self.boards = board.Boards()
        for brd in boards:
            self.boards.AddBoard(board.Board(*brd))
        self.boards.SelectBoards([])

        # Add some test settings
        bsettings.Setup(None)
        bsettings.AddFile(settings_data)

        # Set up the toolchains
        self.toolchains = toolchain.Toolchains()
        self.toolchains.Add('arm-linux-gcc', test=False)
        self.toolchains.Add('sparc-linux-gcc', test=False)
        self.toolchains.Add('powerpc-linux-gcc', test=False)
        self.toolchains.Add('gcc', test=False)

        # Avoid sending any output
        terminal.SetPrintTestMode()
        self._col = terminal.Color()

        self.base_dir = tempfile.mkdtemp()
        if not os.path.isdir(self.base_dir):
            os.mkdir(self.base_dir)

    def tearDown(self):
        shutil.rmtree(self.base_dir)

    def Make(self, commit, brd, stage, *args, **kwargs):
        result = command.CommandResult()
        boardnum = int(brd.target[-1])
        result.return_code = 0
        result.stderr = ''
        result.stdout = ('This is the test output for board %s, commit %s' %
                (brd.target, commit.hash))
        if ((boardnum >= 1 and boardnum >= commit.sequence) or
                boardnum == 4 and commit.sequence == 6):
            result.return_code = commit.return_code
            result.stderr = (''.join(commit.error_list)
                % {'basedir' : self.base_dir + '/.bm-work/00/'})

        result.combined = result.stdout + result.stderr
        return result

    def assertSummary(self, text, arch, plus, boards, outcome=OUTCOME_ERR):
        col = self._col
        expected_colour = (col.GREEN if outcome == OUTCOME_OK else
                           col.YELLOW if outcome == OUTCOME_WARN else col.RED)
        expect = '%10s: ' % arch
        # TODO(sjg@chromium.org): If plus is '', we shouldn't need this
        expect += ' ' + col.Color(expected_colour, plus)
        expect += '  '
        for board in boards:
            expect += col.Color(expected_colour, ' %s' % board)
        self.assertEqual(text, expect)

    def _SetupTest(self, echo_lines=False, **kwdisplay_args):
        """Set up the test by running a build and summary

        Args:
            echo_lines: True to echo lines to the terminal to aid test
                development
            kwdisplay_args: Dict of arguemnts to pass to
                Builder.SetDisplayOptions()

        Returns:
            Iterator containing the output lines, each a PrintLine() object
        """
        build = builder.Builder(self.toolchains, self.base_dir, None, 1, 2,
                                checkout=False, show_unknown=False)
        build.do_make = self.Make
        board_selected = self.boards.GetSelectedDict()

        # Build the boards for the pre-defined commits and warnings/errors
        # associated with each. This calls our Make() to inject the fake output.
        build.BuildBoards(self.commits, board_selected, keep_outputs=False,
                          verbose=False)
        lines = terminal.GetPrintTestLines()
        count = 0
        for line in lines:
            if line.text.strip():
                count += 1

        # We should get two starting messages, then an update for every commit
        # built.
        self.assertEqual(count, len(commits) * len(boards) + 2)
        build.SetDisplayOptions(**kwdisplay_args);
        build.ShowSummary(self.commits, board_selected)
        if echo_lines:
            terminal.EchoPrintTestLines()
        return iter(terminal.GetPrintTestLines())

    def _CheckOutput(self, lines, list_error_boards):
        """Check for expected output from the build summary

        Args:
            lines: Iterator containing the lines returned from the summary
            list_error_boards: Adjust the check for output produced with the
               --list-error-boards flag
        """
        def add_line_prefix(prefix, boards, error_str):
            """Add a prefix to each line of a string

            The training \n in error_str is removed before processing

            Args:
                prefix: String prefix to add
                error_str: Error string containing the lines

            Returns:
                New string where each line has the prefix added
            """
            if boards:
                boards = '(%s) ' % boards
            lines = error_str.strip().splitlines()
            new_lines = [prefix + boards + line for line in lines]
            return '\n'.join(new_lines)

        boards1234 = 'board1,board2,board3,board4' if list_error_boards else ''
        boards234 = 'board2,board3,board4' if list_error_boards else ''
        boards34 = 'board3,board4' if list_error_boards else ''
        boards4 = 'board4' if list_error_boards else ''

        # Upstream commit: no errors
        self.assertEqual(next(lines).text, '01: %s' % commits[0][1])

        # Second commit: all archs should fail with warnings
        self.assertEqual(next(lines).text, '02: %s' % commits[1][1])

        col = terminal.Color()
        self.assertSummary(next(lines).text, 'arm', 'w+', ['board1'],
                           outcome=OUTCOME_WARN)
        self.assertSummary(next(lines).text, 'powerpc', 'w+',
                           ['board2', 'board3'], outcome=OUTCOME_WARN)
        self.assertSummary(next(lines).text, 'sandbox', 'w+', ['board4'],
                           outcome=OUTCOME_WARN)

        # Second commit: The warnings should be listed
        line = next(lines)

        self.assertEqual(line.text,
                         add_line_prefix('w+', boards1234, errors[0]))
        self.assertEqual(line.colour, col.YELLOW)

        # Third commit: Still fails
        self.assertEqual(next(lines).text, '03: %s' % commits[2][1])
        self.assertSummary(next(lines).text, 'arm', '', ['board1'],
                           outcome=OUTCOME_OK)
        self.assertSummary(next(lines).text, 'powerpc', '+',
                           ['board2', 'board3'])
        self.assertSummary(next(lines).text, 'sandbox', '+', ['board4'])

        # Expect a compiler error
        line = next(lines)
        self.assertEqual(line.text, add_line_prefix('+', boards234, errors[1]))
        self.assertEqual(line.colour, col.RED)

        # Fourth commit: Compile errors are fixed, just have warning for board3
        self.assertEqual(next(lines).text, '04: %s' % commits[3][1])
        expect = '%10s: ' % 'powerpc'
        expect += ' ' + col.Color(col.GREEN, '')
        expect += '  '
        expect += col.Color(col.GREEN, ' %s' % 'board2')
        expect += ' ' + col.Color(col.YELLOW, 'w+')
        expect += '  '
        expect += col.Color(col.YELLOW, ' %s' % 'board3')
        self.assertEqual(next(lines).text, expect)
        self.assertSummary(next(lines).text, 'sandbox', 'w+', ['board4'],
                           outcome=OUTCOME_WARN)

        # Compile error fixed
        line = next(lines)
        self.assertEqual(line.text, add_line_prefix('-', boards234, errors[1]))
        self.assertEqual(line.colour, col.GREEN)

        line = next(lines)
        self.assertEqual(line.text, add_line_prefix('w+', boards34, errors[2]))
        self.assertEqual(line.colour, col.YELLOW)

        # Fifth commit
        self.assertEqual(next(lines).text, '05: %s' % commits[4][1])
        self.assertSummary(next(lines).text, 'powerpc', '', ['board3'],
                           outcome=OUTCOME_OK)
        self.assertSummary(next(lines).text, 'sandbox', '+', ['board4'])

        # The second line of errors[3] is a duplicate, so buildman will drop it
        expect = errors[3].rstrip().split('\n')
        expect = [expect[0]] + expect[2:]
        expect = '\n'.join(expect)
        line = next(lines)
        self.assertEqual(line.text, add_line_prefix('+', boards4, expect))
        self.assertEqual(line.colour, col.RED)

        line = next(lines)
        self.assertEqual(line.text, add_line_prefix('w-', boards34, errors[2]))
        self.assertEqual(line.colour, col.CYAN)

        # Sixth commit
        self.assertEqual(next(lines).text, '06: %s' % commits[5][1])
        self.assertSummary(next(lines).text, 'sandbox', '', ['board4'],
                           outcome=OUTCOME_OK)

        # The second line of errors[3] is a duplicate, so buildman will drop it
        expect = errors[3].rstrip().split('\n')
        expect = [expect[0]] + expect[2:]
        expect = '\n'.join(expect)
        line = next(lines)
        self.assertEqual(line.text, add_line_prefix('-', boards4, expect))
        self.assertEqual(line.colour, col.GREEN)

        line = next(lines)
        self.assertEqual(line.text, add_line_prefix('w-', boards4, errors[0]))
        self.assertEqual(line.colour, col.CYAN)

        # Seventh commit
        self.assertEqual(next(lines).text, '07: %s' % commits[6][1])
        self.assertSummary(next(lines).text, 'sandbox', '+', ['board4'])

        # Pick out the correct error lines
        expect_str = errors[4].rstrip().replace('%(basedir)s', '').split('\n')
        expect = expect_str[3:8] + [expect_str[-1]]
        expect = '\n'.join(expect)
        line = next(lines)
        self.assertEqual(line.text, add_line_prefix('+', boards4, expect))
        self.assertEqual(line.colour, col.RED)

        # Now the warnings lines
        expect = [expect_str[0]] + expect_str[10:12] + [expect_str[9]]
        expect = '\n'.join(expect)
        line = next(lines)
        self.assertEqual(line.text, add_line_prefix('w+', boards4, expect))
        self.assertEqual(line.colour, col.YELLOW)

    def testOutput(self):
        """Test basic builder operation and output

        This does a line-by-line verification of the summary output.
        """
        lines = self._SetupTest(show_errors=True)
        self._CheckOutput(lines, list_error_boards=False)

    def testErrorBoards(self):
        """Test output with --list-error-boards

        This does a line-by-line verification of the summary output.
        """
        lines = self._SetupTest(show_errors=True, list_error_boards=True)
        self._CheckOutput(lines, list_error_boards=True)

    def _testGit(self):
        """Test basic builder operation by building a branch"""
        options = Options()
        options.git = os.getcwd()
        options.summary = False
        options.jobs = None
        options.dry_run = False
        #options.git = os.path.join(self.base_dir, 'repo')
        options.branch = 'test-buildman'
        options.force_build = False
        options.list_tool_chains = False
        options.count = -1
        options.git_dir = None
        options.threads = None
        options.show_unknown = False
        options.quick = False
        options.show_errors = False
        options.keep_outputs = False
        args = ['tegra20']
        control.DoBuildman(options, args)

    def testBoardSingle(self):
        """Test single board selection"""
        self.assertEqual(self.boards.SelectBoards(['sandbox']),
                         ({'all': ['board4'], 'sandbox': ['board4']}, []))

    def testBoardArch(self):
        """Test single board selection"""
        self.assertEqual(self.boards.SelectBoards(['arm']),
                         ({'all': ['board0', 'board1'],
                          'arm': ['board0', 'board1']}, []))

    def testBoardArchSingle(self):
        """Test single board selection"""
        self.assertEqual(self.boards.SelectBoards(['arm sandbox']),
                         ({'sandbox': ['board4'],
                          'all': ['board0', 'board1', 'board4'],
                          'arm': ['board0', 'board1']}, []))


    def testBoardArchSingleMultiWord(self):
        """Test single board selection"""
        self.assertEqual(self.boards.SelectBoards(['arm', 'sandbox']),
                         ({'sandbox': ['board4'],
                          'all': ['board0', 'board1', 'board4'],
                          'arm': ['board0', 'board1']}, []))

    def testBoardSingleAnd(self):
        """Test single board selection"""
        self.assertEqual(self.boards.SelectBoards(['Tester & arm']),
                         ({'Tester&arm': ['board0', 'board1'],
                           'all': ['board0', 'board1']}, []))

    def testBoardTwoAnd(self):
        """Test single board selection"""
        self.assertEqual(self.boards.SelectBoards(['Tester', '&', 'arm',
                                                   'Tester' '&', 'powerpc',
                                                   'sandbox']),
                         ({'sandbox': ['board4'],
                          'all': ['board0', 'board1', 'board2', 'board3',
                                  'board4'],
                          'Tester&powerpc': ['board2', 'board3'],
                          'Tester&arm': ['board0', 'board1']}, []))

    def testBoardAll(self):
        """Test single board selection"""
        self.assertEqual(self.boards.SelectBoards([]),
                         ({'all': ['board0', 'board1', 'board2', 'board3',
                                  'board4']}, []))

    def testBoardRegularExpression(self):
        """Test single board selection"""
        self.assertEqual(self.boards.SelectBoards(['T.*r&^Po']),
                         ({'all': ['board2', 'board3'],
                          'T.*r&^Po': ['board2', 'board3']}, []))

    def testBoardDuplicate(self):
        """Test single board selection"""
        self.assertEqual(self.boards.SelectBoards(['sandbox sandbox',
                                                   'sandbox']),
                         ({'all': ['board4'], 'sandbox': ['board4']}, []))
    def CheckDirs(self, build, dirname):
        self.assertEqual('base%s' % dirname, build._GetOutputDir(1))
        self.assertEqual('base%s/fred' % dirname,
                         build.GetBuildDir(1, 'fred'))
        self.assertEqual('base%s/fred/done' % dirname,
                         build.GetDoneFile(1, 'fred'))
        self.assertEqual('base%s/fred/u-boot.sizes' % dirname,
                         build.GetFuncSizesFile(1, 'fred', 'u-boot'))
        self.assertEqual('base%s/fred/u-boot.objdump' % dirname,
                         build.GetObjdumpFile(1, 'fred', 'u-boot'))
        self.assertEqual('base%s/fred/err' % dirname,
                         build.GetErrFile(1, 'fred'))

    def testOutputDir(self):
        build = builder.Builder(self.toolchains, BASE_DIR, None, 1, 2,
                                checkout=False, show_unknown=False)
        build.commits = self.commits
        build.commit_count = len(self.commits)
        subject = self.commits[1].subject.translate(builder.trans_valid_chars)
        dirname ='/%02d_of_%02d_g%s_%s' % (2, build.commit_count, commits[1][0],
                                           subject[:20])
        self.CheckDirs(build, dirname)

    def testOutputDirCurrent(self):
        build = builder.Builder(self.toolchains, BASE_DIR, None, 1, 2,
                                checkout=False, show_unknown=False)
        build.commits = None
        build.commit_count = 0
        self.CheckDirs(build, '/current')

    def testOutputDirNoSubdirs(self):
        build = builder.Builder(self.toolchains, BASE_DIR, None, 1, 2,
                                checkout=False, show_unknown=False,
                                no_subdirs=True)
        build.commits = None
        build.commit_count = 0
        self.CheckDirs(build, '')

    def testToolchainAliases(self):
        self.assertTrue(self.toolchains.Select('arm') != None)
        with self.assertRaises(ValueError):
            self.toolchains.Select('no-arch')
        with self.assertRaises(ValueError):
            self.toolchains.Select('x86')

        self.toolchains = toolchain.Toolchains()
        self.toolchains.Add('x86_64-linux-gcc', test=False)
        self.assertTrue(self.toolchains.Select('x86') != None)

        self.toolchains = toolchain.Toolchains()
        self.toolchains.Add('i386-linux-gcc', test=False)
        self.assertTrue(self.toolchains.Select('x86') != None)

    def testToolchainDownload(self):
        """Test that we can download toolchains"""
        if use_network:
            with test_util.capture_sys_output() as (stdout, stderr):
                url = self.toolchains.LocateArchUrl('arm')
            self.assertRegexpMatches(url, 'https://www.kernel.org/pub/tools/'
                    'crosstool/files/bin/x86_64/.*/'
                    'x86_64-gcc-.*-nolibc_arm-.*linux-gnueabi.tar.xz')

    def testGetEnvArgs(self):
        """Test the GetEnvArgs() function"""
        tc = self.toolchains.Select('arm')
        self.assertEqual('arm-linux-',
                         tc.GetEnvArgs(toolchain.VAR_CROSS_COMPILE))
        self.assertEqual('', tc.GetEnvArgs(toolchain.VAR_PATH))
        self.assertEqual('arm',
                         tc.GetEnvArgs(toolchain.VAR_ARCH))
        self.assertEqual('', tc.GetEnvArgs(toolchain.VAR_MAKE_ARGS))

        self.toolchains.Add('/path/to/x86_64-linux-gcc', test=False)
        tc = self.toolchains.Select('x86')
        self.assertEqual('/path/to',
                         tc.GetEnvArgs(toolchain.VAR_PATH))
        tc.override_toolchain = 'clang'
        self.assertEqual('HOSTCC=clang CC=clang',
                         tc.GetEnvArgs(toolchain.VAR_MAKE_ARGS))

    def testPrepareOutputSpace(self):
        def _Touch(fname):
            tools.WriteFile(os.path.join(base_dir, fname), b'')

        base_dir = tempfile.mkdtemp()

        # Add various files that we want removed and left alone
        to_remove = ['01_of_22_g0982734987_title', '102_of_222_g92bf_title',
                     '01_of_22_g2938abd8_title']
        to_leave = ['something_else', '01-something.patch', '01_of_22_another']
        for name in to_remove + to_leave:
            _Touch(name)

        build = builder.Builder(self.toolchains, base_dir, None, 1, 2)
        build.commits = self.commits
        build.commit_count = len(commits)
        result = set(build._GetOutputSpaceRemovals())
        expected = set([os.path.join(base_dir, f) for f in to_remove])
        self.assertEqual(expected, result)

if __name__ == "__main__":
    unittest.main()
