#include <stdio.h>

int main(void) {
    int x = 100;
    int y = 50;
    int z;

    z = x++ + --y;   // --y; z = x + y; x++ 
    printf("%i %i %i\n", x, y, z);
}