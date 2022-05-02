#include <stdio.h>

/*
 *  When you decide to pass an array to a function, the compiler only passes a pointer to the first element of
 *  the array.  Confusingly, you can use several differnt syntaxes for the call.  Pehaps the most descriptive 
 *  is:
 *              void print_2(int* ptr)
 *
 *  which clearly shows the array is really passed as a pointer.  However, an alternate and equivalent syntax is:
 *              void print_1(int ptr[])
 * 
 *  which gives the impression that the whole array is being passed.  This is not the case.  Note that the size of the array 
 *  is not specified in either syntax.  This means the function being called has no idea how big the array actually is.  To
 *  circumvent this problem, you can pass an additional parameter specifying the number of elements in the array:
 *              void print_3(int ptr[], int size)
 *              void print_4(int* ptr, int size)
 *
 *  Note that the sizeof operator correctly shows the size in bytes of the array in the calling program.  However in the called
 *  function we only have a pointer passed and sizeof correctly reports the size of a pointer parameter.
 */

void print_1(int ptr[])
{
    printf("sizeof ptr = %li\n", sizeof(ptr));
}
void print_2(int* ptr)
{
    printf("sizeof ptr = %li\n", sizeof(ptr));
}
void print_3(int ptr[], int size)
{
    for(int i = 0; i < size; i++)
        printf("ptr[%i] = %i\n", i, ptr[i]);
}
void print_4(int* ptr, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("ptr[%i] = %i\n", i, *ptr++);
    }
}

int main(void)
{
    int a[] = {10, 20, 30, 40, 50};
    
    printf("sizeof a = %li\n", sizeof(a));
    int size = sizeof(a)/sizeof(int);
    print_1(a);
    print_2(a);
    print_3(a, size);
    print_4(a, size);
}
