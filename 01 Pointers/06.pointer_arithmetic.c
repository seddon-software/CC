#include <stdio.h>

/*
 */

int main(void)
{
    int x = 100;
    double d = 2.718281828459045235360287471352;

    int* px = &x;
    double* pd = &d;

    printf("sizeof int = %li\n", sizeof(int));        
    printf("sizeof double = %li\n", sizeof(double));

    printf("\nincrementing int*\n");
    for(int i = 0; i < 5; i++)
    {
        printf("%p\n", px);
        px++;
    }

    printf("\nincrementing double*\n");
    for(int i = 0; i < 5; i++)
    {
        printf("%p\n", pd);
        pd++;
    }
}