#include <stdio.h>

/*
 *  In C, a pointer can point at a single type of variable.  The declaration:
 *          int* px = &x;
 * 
 *  declares px as of type int*, which means a pointer to int.  On the next line we assign px as &x (address of x).  Note that this
 *  can be done in one line as with y: 
 *              int* py = &y;
 *
 *  It is important that you realize we are creating a variable called px with type int* and not a variable called *px.  The * in the 
 *  declaration says: this variable is a pointer.  Later in the example we use * again.  However this time the * is not used in a
 *  declaration, rather it is just used in code.  This time the * has a different meaning: dereference the pointer (get the data at the 
 *  end of the pointer).  These different meanings of * in different contexts is a constant source of confusion for newbies:
 *      * in declaration => I am a pointer
 *      * in code        => dereference the pointer
 *
 *  Finally, note that when you want to print an address, use %p as in:
 *              printf("px = %p\n", px);
 */

int main(void)
{
    int x = 100;
    int* px;
    px = &x;

    printf("x = %i\n", x);
    printf("*px = %i\n", *px);

    printf("&x = %p\n", &x);
    printf("px = %p\n", px);

    int y = 200;
    int* py = &y;

    printf("y = %i\n", y);
    printf("*py = %i\n", *py);

}