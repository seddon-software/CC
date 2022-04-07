/*
 *  Inputing values for a struct with scanf is straightforward.  Just remember the & for each component.
 */

#include <stdio.h>

typedef struct
{
    int x;
    int y;
    int z;
} Point;

int main()
{
    Point p;
    
    // input values
    printf("Enter x, y, x for struct: ");
    fflush(stdout);
    scanf("%i%i%i", &p.x, &p.y, &p.z);
    
    // print components
    printf("p = %i, %i, %i\n", p.x, p.y, p.z);
}