#include <stdio.h>

/*
 *  When you need to input from the keyboard into a int, you can use scanf.  This function places the data in a memory location,
 *  which is specified as a pointer, namely &x.  Note that scanf doesn't prompt you for data, so its advisable to use printf to
 *  prompt for input.
 */

int main(void)
{
    int x;
    printf("Enter a int:");
    fflush(stdout);         // flush output to screen
    scanf("%i", &x);
    printf("x = %i\n", x);    
}