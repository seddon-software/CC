#include <stdio.h>

/*
 *  Local variables are stored on the stack and are only valid in their stack frame (inside the {}).  If we make a call to a function,
 *  we can't use local variables from the calling frame.  However we can pass pointers by copy the a function.  When a pointer is 
 *  copied, the copy still points to the same place as the original.  If we arrange to pass pointers to local variables in the 
 *  calling frame, the function will have indirect access to the calling frame's local variables. 
 * 
 *  In the swap function we pass pointers to x and y, namely &x and &y.  In the function itself, px and py are initialized with these
 *  values, as if we assigned:
 *          px = &x
 *          py = &y
 *  Now px points at x and py points at y.  That being the case, deferencing px will get the value of x as *px and similarly *py
 *  will be y.  We say:
 *          *px is an alias for x
 *          *py is an alias for y
 *  This use of pointers effectively extends the scope of local variables from the calling frame to the function's stack frame. 
 */

void swap(int* px, int* py)
{
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}

int main(void)
{
    int x = 100;
    int y = 200;
    printf("x,y = %i,%i\n", x, y);    
    swap(&x, &y);
    printf("x,y = %i,%i\n", x, y);    
}