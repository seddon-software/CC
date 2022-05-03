#include <stdio.h>
#include <stdlib.h>

/*
 *  Multi-dimensional run time arrays, i.e. those created on the heap, can be of arbitrary size, or even irregular.  This so 
 *  called ragged array is two dimensional, but with an odd shape:
 *              xxx
 *              xx
 *              xxxxx
 *              xx
 * 
 *  Note that the base pointer, "ptr" has to be a level 2 pointer.  This points at a set of heap based one dimensional arrays.  
 *  Hence the allocation:
 *              int** ptr = malloc(4*sizeof(int*));
 * 
 *  The one dimensional arrays have a level 1 pointer (int*) as their base, but are of various sizes.  When we print out the
 *  multi-dimensional array, entries such as ptr[1][3] which are not part of the array will just pick up whatever data is on 
 *  the heap (possibly garbage).
 */

int main(void)
{
    int** ptr = malloc(4*sizeof(int*));
    ptr[0] = malloc(3*sizeof(int));
    ptr[1] = malloc(2*sizeof(int));
    ptr[2] = malloc(5*sizeof(int));
    ptr[3] = malloc(2*sizeof(int));
    ptr[0][0] = 1;
    ptr[0][1] = 2;
    ptr[0][2] = 3;
    ptr[1][0] = 4;
    ptr[1][1] = 5;
    ptr[2][0] = 6;
    ptr[2][1] = 7;
    ptr[2][2] = 8;
    ptr[2][3] = 9;
    ptr[2][4] = 10;
    ptr[3][0] = 11;
    ptr[3][1] = 12;

    for(int row = 0; row < 4; row++)
        for(int col = 0; col < 5; col++)
            printf("ptr[%i][%i] = %i\n", row, col, ptr[row][col]);
}