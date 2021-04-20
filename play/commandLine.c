#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv, char** env) {
    printf("%i \n", argc);
    for(int i = 1; i < argc; i++) {
        printf("%s \n", argv[i]);
    }
    for(int i = 0; i < 4; i++) {
        printf("%s \n", env[i]);
    }
    exit(23);
}