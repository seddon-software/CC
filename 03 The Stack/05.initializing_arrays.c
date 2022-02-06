#include <stdio.h>

/*
 *  Stack based variables are not initialized by default, but global variable are zero initialized.  
 
 *  When intializing arrays, the rules are slightly modified.  Global arrays and uninitialized stack based (local) arrays follow 
 *  the general rule, but if a local array is partially initialized, then the remainder of the array is set to zero.  Note that 
 *  initializing with {}, as with array "c" below, is sufficient to set all values of the array to zero.
 */

int a[5];       // global, initialized to zero 

int main(void)
{
    int b[5];       // unitialized

    for(int i = 0; i < 5; i++)
        printf("b[%i]=%i\n", i, b[i]);
    printf("\n");

    int c[5] = {};  // initialized to zero

    for(int i = 0; i < 5; i++)
        printf("c[%i]=%i\n", i, c[i]);
    printf("\n");

    for(int i = 0; i < 5; i++)
        printf("a[%i]=%i\n", i, a[i]);
    printf("\n");

    int array1D[5] = {99, 88};      // remaining items initailzed to zero
    for(int i = 0; i < 5; i++)
        printf("array1D[%i]=%i\n", i, array1D[i]);
    printf("\n");

    int array2D[][5] = {{99},{88}};  // [0][0] and [1][0] initialized, remaining items initialzed to zero
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 5; j++)
        printf("array2D[%i,%i]=%i\n", i, j, array2D[i][j]);
    printf("\n");
}