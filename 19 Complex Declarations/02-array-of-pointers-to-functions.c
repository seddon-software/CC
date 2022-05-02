#include <stdio.h>
#include <stdlib.h>

int f1(int x, int y)
{
    return x + y;
} 

int f2(int x, int y)
{
    return x + y;
} 

int f3(int x, int y)
{
    return x + y;
} 

/* precedence table
   ================

  () => functions
  [] => arrays

  *  => pointer
*/

int main(void)
{
    int (*p[3])(int, int) = {f1, f2, f3};
    printf("%i\n", p[0](10, 1));
    printf("%i\n", p[1](20, 2));
    printf("%i\n", p[2](30, 3));
}