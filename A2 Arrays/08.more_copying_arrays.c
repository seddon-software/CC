#include <stdio.h>

/*
 *  As established earlier, when an array is passed as a parameter, in reality only a pointer to the start of the array is passed.
 *  We can take advantage of this to work with sub arrays.  In the line:
 *              copy_array(source+3, subArray, 5);
 * 
 *  the first parameter points to the fourth element of the 'source' array rather than its beginning.  The 'copy_array' function
 *  will assume this is the start of the array and copy 5 elements starting from this position.  Thus 'subArray' ends up with
 *  elements 4, 5, 6, 7 and 8 of the 'source' array.
 * 
 *  We can perform a similar trick when printing a sub array as in:
 *              print_array(source+3, 5);
 */


void print_array(int array[], int size)
{
    printf("array = ");
    for(int i = 0; i < size; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");
}

void copy_array(int source[], int target[], int size)
{
    for(int i = 0; i < size; i++)
    {
        target[i] = source[i];
    }
}

int main(void)
{
    int source[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int target[10];

    // copy entire array
    copy_array(source, target, 10);
    print_array(source, 10);
    print_array(target, 10);

    // copy sub array
    int subArray[5];
    copy_array(source+3, subArray, 5);
    print_array(subArray, 5);

    // print sub array
    print_array(source+3, 5);
}

