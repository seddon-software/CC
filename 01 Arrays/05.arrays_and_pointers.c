#include <stdio.h>

/*
 *  Pointers are often used with arrays.  If we take a pointer an point it at the start of an array, we can then use it to step through 
 *  the array.  Fundamental to this is the fact that when you increment a pointer by 1 its value changes by the size of the item it 
 *  points at.  This means the pointer steps to the next item in the array.
 */

int main(void)
{
    int a[5] = { 100, 200, 300, 400, 500};
    int* ptr;

    // point at start of the array
    ptr = &a[0];
    printf("a[0] = %i\n", *ptr);
    ptr++;      // move to next item
    printf("a[1] = %i\n", *ptr);
    ptr++;      // move to next item
    printf("a[2] = %i\n", *ptr);
    ptr++;      // move to next item
    printf("a[3] = %i\n", *ptr);
    ptr++;      // move to next item
    printf("a[4] = %i\n", *ptr);
    ptr++;      // move to next item

    // now see how ptr changes
    ptr = &a[0];
    for(int i = 0; i < 5; i++)
    {
        printf("ptr = %p\n", ptr);
        ptr++;
    }
}
