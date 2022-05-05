/*
 *  When working with pointers and side effect operators such as ++, be aware that every expression yields a value in addition to what the side effect operators achieve.  In particular notice that in the
 *  code below:
 *              p++;
 * 
 *  has exactly the same effect as:
 *              *p++;
 * 
 *  The explanation is that in the first example, the side effect operator increments p and the expression yields p; the yielded result is not used.  In the second example the side effect operator again increments p,
 *  but this time the expression yields *p and again the yielded result is not used.  Thus the * is not contributing anything in this example - it's just confusing to see it there.  Note that the 
 *  yielded result would have an effect if we assign it to something, as in:
 *              int x;
 *              x = *p++;
 * 
 *  In this case p still gets incremented, but x gets assigned the value of *p before p is incremented.  Try to avoid adding a redundant and confusing code.
 */

#include <stdio.h>

int main(void)
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int* ptr;
    ptr = a;
    ptr++;                      // this is fine
    printf("*ptr = %i\n", *ptr);
    printf("ptr = %p\n", ptr);
    *ptr++;                     // DON'T do this
    printf("*ptr = %i\n", *ptr);
    printf("ptr = %p\n", ptr);
}