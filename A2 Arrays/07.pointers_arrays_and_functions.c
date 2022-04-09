#include <stdio.h>

/*
 *  When arrays can be passed to functions what is actually passed is a pointer to the first elemeny of the array.  The receiving 
 *  function does not know how big the array is.  If you want to specify the size, this necessitates a second parameter:
 * 
 *              printf("size of myArray %i", sizeof(myArray));
 * 
 *  In this example we want to establish that arrays are passed by pointer.  Consider
 * 
 *      1) double_array and double_array2 produce the same results 
 *      2) the size of array 'a' is 20 bytes (5 items x 4 bytes each)
 *      3) the size of 'myArray' is 8 bytes (int* are 8 bytes)
 *      4) the array parameter can be passed as 
 *              int myArray[] or int* myArray
 *      5) both
 *              printf("start of the array is at: %p\n", &a[0]);
 *              printf("value of myArray is : %p\n", myArray);
 * 
 *          yield the same address.

 * 
 *  All of this backs up the claim that the array is passed as a pointer to the start of the array.
 * 
 *  Note the size of the array (number of elements) can be computed by the expression:
 *              int size = sizeof(a)/sizeof(int);
 */

void double_array2(int* myArray, int size)
{
    printf("value of myArray is : %p\n", myArray);

    printf("size of 'myArray' = %i bytes\n", sizeof(myArray));
    for(int i = 0; i < size; i++)
    {
        myArray[i] *= 2;
    }
}

void double_array(int myArray[], int size)
{
    printf("value of myArray is : %p\n", myArray);

    printf("size of 'myArray' = %i bytes\n", sizeof(myArray));
    for(int i = 0; i < size; i++)
    {
        myArray[i] *= 2;
    }
}

void print_array(int myArray[], int size)
{
    printf("array = ");
    for(int i = 0; i < size; i++)
    {
        printf("%i ", myArray[i]);
    }
    printf("\n");
}

int main(void)
{
    int a[] = { 100, 200, 300, 400, 500};          // array of 5 ints
    int size = sizeof(a)/sizeof(int);
    printf("size of 'a' = %i bytes\n", sizeof(a));
    printf("elements in 'a' = %i\n", size);

    printf("start of the array is at: %p\n", &a[0]);
    double_array(a, size);
    print_array(a, size);

    double_array2(a, size);
    print_array(a, size);
}
