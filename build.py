#!/usr/bin/env python

"""
Builds PDF files for practice exams and sample problems (both blank and
solution). Uses Lyx 2.3 with LuaTex internally. Results will be placed in
build subdirectory. Probably only works on Windows.
"""

import os

__author__      = "Ruben Acuna"
__copyright__   = "Copyright 2019, Ruben Acuna"

build_folder = os.sep + "build"
cwd = os.getcwd()
tex_toolchain = "pdf5" #LuaTex
lyx_bin = "Lyx"

# preparation
if not os.path.isdir(build_folder):
    os.mkdir(build_folder)
#TODO: clean up old build folder if exists

# build
lyx_filenames = [x for x in os.listdir(".") if x.endswith(".lyx")]
for lyx_filename in lyx_filenames:
    blank_out_filename = cwd + build_folder + os.sep + lyx_filename[:-3] + "pdf"
    soln_out_filename = cwd + build_folder + os.sep + lyx_filename[:-4] + "_soln.pdf"

    # reference: https://wiki.lyx.org/FAQ/ImportExport
    blank_para = "-x \"command-sequence branch-activate blank; branch-deactivate soln\"" + " --export-to " + tex_toolchain + " " + blank_out_filename + " " + lyx_filename
    soln_para = ("-x \"command-sequence branch-activate soln; branch-deactivate blank\" --export-to %s %s %s" % (tex_toolchain, soln_out_filename, lyx_filename))

    if "_opt_" in lyx_filename:
        continue

    cmd_blank = lyx_bin + " " + blank_para
    os.system(cmd_blank)

    if "exam" not in lyx_filename:
        cmd_soln = lyx_bin + " " + soln_para
        os.system(cmd_soln)

#TODO: copy code samples folder
#TODO: copy handouts folder
#TODO: copy .md and .txt from root