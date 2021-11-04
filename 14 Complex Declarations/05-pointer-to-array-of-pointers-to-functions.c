#include <stdio.h>
#include <stdlib.h>

int f1(int x, int (*fn)(int))
{
    return x + fn(x);
} 

int f2(int x, int (*fn)(int))
{
    return x + fn(x);
} 

int f3(int x, int (*fn)(int))
{
    return x + fn(x);
} 

int doubleIt(int x)
{
    return 2 * x;
}

int tripleIt(int x)
{
    return 3 * x;
}

int quadIt(int x)
{
    return 4 * x;
}


int main(void)
{
    // an array of 3 pointers to functions with 2 parameters
    // the parameters are:
    //      int
    //      pointer to a function: int fn(int)
    int (*p[3])(int, int(*)(int)) = {f1, f2, f3};    
    printf("%i\n", p[0](10, doubleIt));
    printf("%i\n", p[1](11, tripleIt));
    printf("%i\n", p[2](12, quadIt));

    // a pointer to functions
    int ((*q))(int, int(*)(int));
    q = &f1;        // the & is optional
    printf("%i\n", q(10, doubleIt));

    // pointer to an array of 3 pointers to functions
    int (*(*r)[3])(int);
    // an array of 3 pointers to functions
    int (*a[3])(int) = {doubleIt, tripleIt, quadIt};
    r = &a;         // the & is required to suppress a warning
    printf("%i\n", r[0][0](5));
    printf("%i\n", (*r)[0](5));
    printf("%i\n", (*(*r))(5));
    printf("%i\n", (**r)(5));
}
