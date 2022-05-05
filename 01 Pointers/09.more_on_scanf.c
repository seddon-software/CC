#include <stdio.h>

/*
 *  It's a common misconception that scanf always requires you to use an & the read in data.  However as this example shows this
 *  is not true.  What scanf requires is a Level 1 pointer.  
 * 
 *  We start with an int x and then define a level 1 pointer px that points at x.  Next we define a level 2 pointer ppx that points
 *  to px.  Thus we have a chain:
 *          ppx ---> px ---> x
 * 
 *  We can now input into x directly or via px or via ppx.  In each case scanf takes a level 1 parameter:
 *          &x   : x=level 0, &x=level 1
 *          px   : px = level 1
 *          ppx  : ppx = lecvel2, *ppx=level 1
 */

int main(void)
{
    int x;
    int* px = &x;
    int** ppx = &px;

    printf("Enter a int: ");
    fflush(stdout);
    scanf("%i", &x);
    printf("x = %i\n", x);    

    printf("Enter a int: ");
    fflush(stdout);
    scanf("%i", px);        // px is already a pointer (level 1)
    printf("x = %i\n", x);    
    
    printf("Enter a int: ");
    fflush(stdout);
    scanf("%i", *ppx);      // ppx (level 2) is pointing at a pointer (level 1) and hence needs * to dereference
    printf("x = %i\n", x);
}