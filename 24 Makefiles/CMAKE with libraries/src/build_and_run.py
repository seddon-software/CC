'''
This Python script builds 2 executables and then runs them.  Invoke as:
    python build_install_and_test.py
'''

import os, subprocess, time, glob

N = 1

def printMessage(m):
    time.sleep(N)
#    subprocess.call(["clear"])
    print(m)
    print("-" *  len(m))
    print()
    input("?")

def call(cmd):
    print(cmd)
    time.sleep(N)
    subprocess.call(cmd.split())

# Use CMake to build extension module
printMessage("Use CMake to build executables")
call("rm -rf build")
call("cmake -S src -B build")
call("cmake --build build")

printMessage("now run the executable")
os.chdir("build")
call("main")
