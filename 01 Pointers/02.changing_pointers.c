#include <stdio.h>

/*
 *  The idea behind pointers is that they are mutable (can be changed).  A pointer can point at many different items during its
 *  lifetime.  Note, however, that a pointer can only point at one type of item; if you have a pointer to an int (int*) then
 *  this pointer can only ever point to various ints and never point to say a float.
 * 
 *  In y=this example we first initialize p to point at int x and subsequently change p to point at int y.
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