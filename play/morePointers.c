#include <stdio.h>

int main(void) {
    int x = 100;  // x is Level 0;
    int* px;      // px is a Level 1 pointer
    int** py;     // py is a Level 2 pointer

    px = &x;       // x is Level 0, &x is Level 1, & increases level by 1
    py = &px;      // px = L1,  &px= L1+1=L2

    // py = px;       // LHS=2, RHS=1
    // py = 7;        // LHS=2, RHS=0
    printf("%i\n", x);      // L0
    printf("%i\n", *px);    // px=L1, *px=L1-1=L0
    printf("%i\n", **py);   // py=L2, *py=L1, **py=L0
    
    scanf("%i", &x);        // scanf wants a L1 quantity
    scanf("%i", px);        // scanf wants a L1 quantity
    scanf("%i", *py);        // scanf wants a L1 quantity
    *px = **py;    // LHS=0, RHS=0
}