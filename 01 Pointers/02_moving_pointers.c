#include <stdio.h>

/*
 *  Pointers can be changed.  Here we first initialize p to point at x and subsequently change p to point at y.
 */

int main(void)
{
    int x = 100;
    int y = 200;
    printf("&x = %p\n", &x);
    printf("&y = %p\n", &y);

    int* p = &x;
    printf("*p = %i\n", *p);
    printf("px = %p\n", p);

    p = &y;
    printf("*p = %i\n", *p);
    printf("p = %p\n", p);    
}