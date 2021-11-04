#include <stdio.h>
#include <stdlib.h>

// use typedefs to simplify notation
typedef int F2(int);
typedef int F1(int, F2);

F1 f1;    // function prototypes (go in header file)
F1 f2;
F1 f3;


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
    F1 *p[3] = {f1, f2, f3};    
    printf("%i\n", p[0](10, doubleIt));
    printf("%i\n", p[1](11, tripleIt));
    printf("%i\n", p[2](12, quadIt));

    F1 *q;
    q = &f1;        // the & is optional
    printf("%i\n", q(10, doubleIt));

    F2 *(*r)[3];
    F2 *a[3] = {doubleIt, tripleIt, quadIt};
    r = &a;         // the & is required
    printf("%i\n", r[0][0](5));
}
