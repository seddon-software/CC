#include <stdio.h>

/*
 */

int main(void)
{
    int a[] = {10, 20, 30, 40, 50};
    int* p = &a[0];
        
    // arrays
    printf("&a[0] = %p\t", &a[0]);
    printf("&a[1] = %p\t", &a[1]);
    printf("&a[2] = %p\t", &a[2]);
    printf("&a[3] = %p\t", &a[3]);
    printf("&a[4] = %p\n", &a[4]);

    // arrays
    printf("a     = %p\t", a);
    printf("a+1   = %p\t", a+1);
    printf("a+2   = %p\t", a+2);
    printf("a+3   = %p\t", a+3);
    printf("a+4   = %p\n", a+4);

    // pointers
    printf("p     = %p\t", p);
    printf("p+1   = %p\t", p+1);
    printf("p+2   = %p\t", p+2);
    printf("p+3   = %p\t", p+3);
    printf("p+4   = %p\n", p+4);

    // pointers
    printf("&p[0] = %p\t", &p[0]);
    printf("&p[1] = %p\t", &p[1]);
    printf("&p[2] = %p\t", &p[2]);
    printf("&p[3] = %p\t", &p[3]);
    printf("&p[4] = %p\n", &p[4]);
}