function pause()
{
    set +x
    echo '?'
    read x
    set -x
}

generate_lib.sh
pause
build_lib.sh | grep gcc
pause
generate_src.sh
pause
build_src.sh
pause
../build/main
pause
clean.sh
