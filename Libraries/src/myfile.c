#include <stdio.h>
#include <math.h>

double sumOfRoots(int lo, int hi)
{
    int i;
    double result = 0.0;
    for(i = lo; i <= hi; i++)
    {
	result += sqrt((double)i);
    }
    return result;
}

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
    printf("%lf\n", sumOfRoots(1000, 10000000));
    printf("%lf\n", sumOfRoots(1000, 11000000));
    printf("%lf\n", sumOfRoots(1000, 12000000));
}

