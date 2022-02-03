#include <stdio.h>

/*
 */

void f()
{
    printf("this is function f\n");
}
void g()
{
    printf("this is function g\n");
}

void call(void (*fptr)(void))
{
    fptr();
}
int main(void)
{
    call(f);
    call(g);    
}