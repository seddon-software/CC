#include <stdio.h>

typedef int* INTPTR;  // doesn't declare anything
                      // but does define an alias for int*
typedef int** LEVEL2PTR;

int main(void) {
    int x = 100;
    INTPTR px;
    LEVEL2PTR ppx;
    px = &x;
    ppx = &px;
}