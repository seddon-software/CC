#include <stdio.h>

/*
 *  Pointers in C are normally restricted to point to a single type.  However, sometimes you might need to define a generic pointer 
 *  that can point to any type.  Enter:
 *              void*
 * 
 *  The void* pointer can point at any type;  void* are untyped pointers.  However, the compiler will not know what type is at the 
 *  end of the pointer, so you are not allowed to dereference a void*, nor increment it.  What you can do is to cast it to typed
 *  pointer and then normal service is resumed.
 * 
 *  void* pointers are often used in generic functions.  A typical use would be to zero initialize an array.  In the code below we
 *  use void* pointers in the "clear()" function.  This allows "clear()" to work with both integer and double type arrays.  Recall 
 *  you need to tell "clear()" the start and end of the arrays (hence the two parameters).  The void* pointers are converted to char*
 *  arrays in the "clear()" function because a char occupies a single byte.  Then all bytes between the start and end of the array 
 *  can be set to '\0' (i.e. zero). 
 * 
 *  There are several examples of void* pointers used in the standard C library.  You probably don't need them in your own code.
 */

void clear(void* start, void* end)
{
    for(char* p = start; p < (char*)end; p++)
    {
        *p = '\0';
    } 
}
void print_int(int* start, int* end)
{
    for(int* p = start; p < (int*)end; p++)
    {
        printf("%i, ", *p);
    }
    printf("\n");     
}
void print_double(double* start, double* end)
{
    for(double* p = start; p < (double*)end; p++)
    {
        printf("%lf, ", *p);
    }         
    printf("\n");     
}

int main(void)
{
    int a[] = {10, 20, 30, 40, 50};
    double b[] = {1.2, 2.4, 3.6, 4.8}; 
    clear(a, a+5);
    clear(b, b+4);
    print_int(a, a+5);
    print_double(b, b+4);
}
