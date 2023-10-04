'''
This Python script builds 2 executables and then runs them.  Invoke as:
    python build_install_and_test.py
'''

import os, subprocess, time, glob

def printMessage(m):
    time.sleep(5)
#    subprocess.call(["clear"])
    print(m)
    print("-" *  len(m))
    print()
    input("?")

def call(cmd):
    print(cmd)
    time.sleep(5)
    subprocess.call(cmd.split())


# Use CMake to build extension module
printMessage("Use CMake to build executables")
call("rm -rf build")
call("cmake -S src -B build")
call("cmake --build build")

printMessage("now run the 2 executables")
os.chdir("src")
printMessage("run f")
call("f")
printMessage("run g")
call("g")

# clean up
printMessage("clean up")
call("rm -rf build")

