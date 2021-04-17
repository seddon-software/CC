#include <stdio.h>

int f(int x, double y)
{
    printf("x=%i y=%lf\n", x, y);
    return 0;
}

void h(int (*g)(int, double))
{
    g(66, 3.75);
}

int main(void)
{
    int a[][3] = {{1, 3, 5}, { 2, 4, 6}};
    int (*p)[3];
    p = a;
    p[0][0] = -1;

    typedef int(*FP)(int, double);
    int (*g)(int, double);
    g = f;
    g(6, 3.5);
    h(g);
    FP fp;
    fp = f;
    h(fp);
    return 0; 
}