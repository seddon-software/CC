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

int square(int x)
{
    return x * x;
}

int cube(int x)
{
    return x * x * x;
}

int quad(int x)
{
    return x * x * x * x;
}

int main(void)
{
    int (*p[3])(int, int (*)(int)) = {f1, f2, f3};
    printf("%i\n", p[0](10, square));
    printf("%i\n", p[1](11, cube));
    printf("%i\n", p[2](12, quad));
}