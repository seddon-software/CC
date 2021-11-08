#include <stdio.h>
#include <stdlib.h>
#include <mcheck.h>

int* f2()
{
    int* ptr;

    fprintf(stderr, "size of int: %li\n", sizeof(int));
    ptr = (int*) malloc(30 * sizeof(int));
    for(int i = 0; i < 30; i++)
    {
        ptr[i] = i * i;
        printf("%i ", ptr[i]);
    }
    return ptr;
}

int* f1()
{
    int x = 100;
    x++;
    printf("%i\n", x);
    return f2();
}

void f3(int* ptr)
{
    fprintf(stderr, "size of double: %li\n", sizeof(double));
    double* p = (double*) malloc(sizeof(double) * 10);
    p[0] = 3.14159;
    //free(ptr);
}

int main()
{
    int* ptr;
    
    mtrace();	// will generate text info file
    ptr = f1();
    //ptr++;
    f3(ptr);
    printf("\n");
    return 0;
}

