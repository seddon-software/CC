#include <stdio.h>
#include <math.h>

int fibonacci(int n)
{
    if(n == 0) return 1;
    if(n == 1) return 1;
    if(n > 1) return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    printf("%i\n", fibonacci(32));
    printf("%i\n", fibonacci(33));
    printf("%i\n", fibonacci(34));
}

