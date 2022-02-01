#include <stdio.h>

/*
 *  Pointers can only point at one type of data.  In this example we try and mix types.  The point q can only point at
 *  doubles.  However, the line:
 *          q = p;
 * 
 *  copies an int* to a double*.  Surprisingly, this compiles, but with a warning.  Nevertheless, the code goes badly wrong.  It's
 *  true that q now points to the same place as p, namely at the int x.  However, the compiler thinks q points at a double, which 
 *  is 8 bytes in length and therefore passes 8 bytes to printf.  These 8 bytes will be the 4 bytes of x and 4 other bytes from
 *  the memory surrounding x.  This is probably half of the 8 bytes storage of y - essentially garbage.  Not surprisingly, printf 
 *  goes wrong when print *q.
 */

int main(void)
{
    printf("sizeof double = %li\n", sizeof(double));
    printf("sizeof int = %li\n", sizeof(int));
    int x = 100;
    double y = 3.14159;
    printf("&x = %p\n", &x);
    printf("&y = %p\n", &y);

    int* p = &x;
    double* q = &y;
    printf("*p = %i\n", *p);
    printf("*q = %lf\n", *q);

    q = p;                      // only a warning: incompatable types
 
    printf("q = %p\n", q);      // the address is correct
    printf("*q = %i\n", *q);    // but printf get the data wrong with %i
    printf("*q = %lf\n", *q);   // likewise with %lf
}