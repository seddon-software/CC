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
    int (*p[3])(int, int(*)(int)) = {f1, f2, f3};    
    printf("%i\n", p[0](10, doubleIt));
    printf("%i\n", p[1](11, tripleIt));
    printf("%i\n", p[2](12, quadIt));

    int (*q)(int, int(*)(int));
    q = p[0];     //    q = &f1;
    printf("%i\n", q(10, doubleIt));
}
