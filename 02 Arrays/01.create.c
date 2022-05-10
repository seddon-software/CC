#include <stdio.h>

int z[3];
/*
 *  Arrays are used to store lists.  All items in an array must be of the same type.  Create an uninitialized array:
 *              int myarray[10];
 * 
 *  or an initialized array:
 *              int a[5] = { 100, 200, 300, 400, 500};
 */

int main(void)
{
    int myarray[10];                                // uninitialized
    int a[5] = { 100, 200, 300, 400, 500};          // array of 5 ints
    double b[5] = { 1.11, 2.22, 3.33, 4.44, 5.55};  // array of 5 doubles

    // valid indeces range from 0 to 4
    printf("a[0] = %i\n", a[0]);        
    printf("a[1] = %i\n", a[1]);        
    printf("a[2] = %i\n", a[2]);        
    printf("a[3] = %i\n", a[3]);        
    printf("a[4] = %i\n", a[4]);
    printf("sizeof a in bytes = %li\n", sizeof(a));
    printf("sizeof a = %li\n", sizeof(a)/sizeof(int));

    // and for array of doubles 
    printf("b[0] = %6.2lf\n", b[0]);        
    printf("b[1] = %lf\n", b[1]);        
    printf("b[2] = %lf\n", b[2]);        
    printf("b[3] = %lf\n", b[3]);        
    printf("b[4] = %lf\n", b[4]);
    printf("sizeof b in bytes = %li\n", sizeof(b));
    printf("sizeof a = %li\n", sizeof(b)/sizeof(double));
}
