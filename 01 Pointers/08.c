#include <stdio.h>

/*
 */

int main(void)
{
    int a[] = {10, 20, 30, 40, 50};
    int* p = &a[0];
        
    // dereference arrays using pointer notation
    printf("*a     = %i\t", *a);
    printf("*(a+1) = %i\t", *(a+1));
    printf("*(a+2) = %i\t", *(a+2));
    printf("*(a+3) = %i\t", *(a+3));
    printf("*(a+4) = %i\n", *(a+4));

    // dereference pointers using pointer notation
    printf("*p     = %i\t", *p);
    printf("*(p+1) = %i\t", *(p+1));
    printf("*(p+2) = %i\t", *(p+2));
    printf("*(p+3) = %i\t", *(p+3));
    printf("*(p+4) = %i\n", *(p+4));

    // dereference pointers using array notation
    printf("p[0]   = %i\t", p[0]);
    printf("p[1]   = %i\t", p[1]);
    printf("p[2]   = %i\t", p[2]);
    printf("p[3]   = %i\t", p[3]);
    printf("p[4]   = %i\n", p[4]);

    // dereference arrays using array notation
    printf("a[0]   = %i\t", a[0]);
    printf("a[1]   = %i\t", a[1]);
    printf("a[2]   = %i\t", a[2]);
    printf("a[3]   = %i\t", a[3]);
    printf("a[4]   = %i\n", a[4]);
}