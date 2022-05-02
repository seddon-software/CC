#include <stdio.h>

/*
 *  Arrays can be passed to functions.  In this example we pass an array to two different functions.  The functions have to be
 *  declared as: 
 *              void double_array(int myArray[])
 *              void print_array(int myArray[])
 * 
 *  Note that you do not specify the array size when declaring the "myArray" parameter; we have defined the size with the
 *  preprocessor:
 *              #define SIZE 5
 * 
 *  The function receiving the array does not receive a copy of the original array, but rather a alias for the array.  If the 
 *  function modifies the array (through the alias) then the original array will be changed.
 *  
 *  It turns out that there is more going on when passing arrays to functions.  We will look in more detail later; suffice to say
 *  we do not really pass the whole array to the function, we only pass a pointer to the start of the array.  But more of this 
 *  later.
 */

#define SIZE 5

void double_array(int myArray[])
{
    for(int i = 0; i < SIZE; i++)
    {
        myArray[i] *= 2;
    }
}

void print_array(int myArray[])
{
    printf("array = ");
    for(int i = 0; i < SIZE; i++)
    {
        printf("%i ", myArray[i]);
    }
    printf("\n");
}

int main(void)
{
    int a[SIZE] = { 100, 200, 300, 400, 500};          // array of 5 ints
    double_array(a);
    print_array(a);
}
