#! /bin/bash

function pause()
{
    set +x
    echo ""
    echo $1
    echo '?'
    read x
    set -x
}

clear

# inspect source files
pause "inspect source files"
tree src
tree lib

# generate makefiles for building shared library
pause "generate makefiles for building shared library"
rm -rf build-lib
cmake -S lib -B build-lib

# build the shared library
pause "build the shared library"
cmake --build build-lib

# generate makefiles for building the main program and linking with the shared library
pause "generate makefiles for building the main program and linking with the shared library"
rm -rf build-src
cmake -S src -B build

# build and link the shared library
pause "build and link the shared library"
cmake --build build

# run the resulting program
pause "run the resulting program"
build/main

# clean up
pause "clean up"
rm -rf build-lib build-src
