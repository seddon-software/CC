/*
 *  Functions can return structures.  Recall that functions are only allowed to return one item.  However, since structs contain 
 *  multiple components they could be used indirectly to return multiple results.
 *
 *  Note that it is important to return the struct by copy and not by pointer.  
 */

#include <stdio.h>

typedef struct
{
    int squareA;
    int squareB;
    int squareC;
} Squares;

Squares calculate_multiple_squares(int a, int b, int c)
{
    Squares results;
    results.squareA = a * a;
    results.squareB = b * b;
    results.squareC = c * c;
    return results;
}

int main()
{
    Squares results;
    int a = 10;
    int b = 20;
    int c = 30;
    results = calculate_multiple_squares(a, b, c);
    printf("%i x %i = %i\n", a, a, results.squareA);
    printf("%i x %i = %i\n", b, b, results.squareB);
    printf("%i x %i = %i\n", c, c, results.squareC);
}

