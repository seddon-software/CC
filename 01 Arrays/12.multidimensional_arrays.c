#include <stdio.h>

/*
 *  Multi-dimensional arrays use multiple pairs of [].  Note that you don't need to specify the left most dimension; the compiler
 *  can work it out.
 *  
 *  When passing multi-dimensional arrays as parameters you must also pass the dimensions seperately.  However, because the
 *  compiler is a single pass compiler, all symbols must be declared before they are used; this means you must supply the 
 *  dimensional data before the array:
 *              void print_array_of_int(int rows, int cols, int array[rows][cols])
 */


void print_array_of_int(int rows, int cols, int array[rows][cols])
{
    puts("Printing array of ints");
    for(int row = 0; row < rows; row++)
    {
        for(int col = 0; col < 5; col++)
        {
            printf("%4i", array[row][col]);
            fflush(stdout);
        }
        puts("");       // for new line
    }   
    puts("");       // for new line
}

void print_array_of_double(int rows, int cols, double array[rows][cols])
{
    puts("Printing array of doubles");
    for(int row = 0; row < rows; row++)
    {
        for(int col = 0; col < 5; col++)
        {
            printf("%6.2lf", array[row][col]);
            fflush(stdout);
        }
        puts("");       // for new line
    }   
    puts("");       // for new line
}

int main(void)
{
    // specify all dimensionality
    int results[4][5] =
    {
        { 75, 95, 90, 84, 80 },   /* row 0 */
        { 100, 99, 100, 98, 99 }, /* row 1 */
        { 100, 99, 100, 98, 99 }, /* row 2 */
        { 80, 67, 85, 79, 75 }    /* row 3 */
    };

    // compiler computes size of first dimension (=3)
    double coordinates[][2] =
    {
        { -2.5, 2.71 },           /* (x,y) point 0 */
        { 0.0, 0.0 },             /* (x,y) point 1 */
        { 4.0, 12.03 }            /* (x,y) point 2 */
    };

    print_array_of_int(4, 5, results);
    print_array_of_double(3, 2, coordinates);
}
