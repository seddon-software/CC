#include <stdio.h>
#include <stdlib.h>

int f(int x, int y)
{
    return x + y;
} 

int main(void)
{
    int (*p)(int, int);
    p = f;
    printf("%i\n", p(5, 7));
}