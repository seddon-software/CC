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

printMessage("now run the executables in src")
os.chdir("src")
call("f1")
call("f2")
call("f3")
call("f4")

printMessage("now run the executables in src/d1")
os.chdir("d1")
call("f5")
call("f6")
call("f7")
call("f8")

printMessage("now run the executables in src/d2")
os.chdir("../d2")
call("f9")
call("f10")
call("f11")
call("f12")

# clean up
# printMessage("clean up")
# call("rm -rf build")

