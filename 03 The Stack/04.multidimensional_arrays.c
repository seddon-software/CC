#include <stdio.h>

/*
 *  When you pass a multi-dimensional array to a function, what gets passed is a pointer to the start of the array and dimensional
 *  information.  Note that the function does not known the size of the left most dimension, inline with the way 1 dimensional 
 *  arrays work.  Therefore the calling program should pass this information as an additional parameter, as in:
 *              f(array, 2);
 *              g(array, 2);
 * 
 *  The specification of the array parameter can be expressed in array notation:
 *              double a[][3][4]
 * 
 *  with the left dimension size unspecified, or expressed in pointer notation:
 *              double (*const a)[3][4]
 * 
 *  When using pointer notation, the brackets are necessary to avoid a binding a to [3] since despite appearances, a is a pointer (*a)
 *  and not an array.
 */

void g(double (*const a)[3][4], int size)  // note the brackets in (*const a) - it's important
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                printf("%lf,", a[i][j][k]);
                fflush(stdout);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void f(double a[][3][4], int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                printf("%lf,", a[i][j][k]);
                fflush(stdout);
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main(void)
{
    double array[2][3][4] =
    {
        {    
            { 1.0,  2.0,  3.0,  4.0 },
            { 4.0,  5.0,  6.0,  7.0 },
            { 2.0,  4.0,  6.0,  8.0 }
        },
        {
            { 1.1,  2.1,  3.1,  4.1 },
            { 4.1,  5.1,  6.1,  7.1 },
            { 2.1,  4.1,  6.1,  8.1 }
        }
    };
    f(array, 2);
    g(array, 2);
}
