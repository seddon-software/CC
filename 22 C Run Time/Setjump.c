/****************************************************

    setjump and longjmp

****************************************************/

#include <stdio.h>
#include <setjmp.h>
#include <math.h>

double x;
jmp_buf context;


void f3()
{
    printf("Please enter a number: ");
    // scanf("%lf", &x);
    x = -99;
    if(x < 0) longjmp(context, 5);
    printf("Square root of x = %8.4lf\n", sqrt(x));
}

void f2()
{
    f3();
}

void f1()
{
    f2();
}

int main(void)
{
    int reason;     // return code from setjmp/longjmp
    
    reason = setjmp(context);
    if (reason == 0)    /* normal return */
        f1();
    else
        printf("error number %i\n", reason);
}
