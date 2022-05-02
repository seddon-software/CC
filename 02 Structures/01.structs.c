/*
 *  Structures are used to create records or lists of items.  Unlike arrays, the items do not have to be
 *  the same types.  To access the components of a struct we use dot notation:
 *              p1.x
 * 
 *  Note structs are initialized with {}.  As with other stack based variables, because p1 is unitialized
 *  it gets set to random values, but p2 is initialized (although with no values) and get set to zeros. 
 *  Structs can be initialised by position:
 *              struct Point p3 = {11.11, 22};
 * 
 *  or by component names (more verbose, but probably a good thing):
 *                  struct Point p4 = {.x = 33.33, .y = 44};
 */

#include <stdio.h>

struct Point
{
    double x;
    int y;
};

int main()
{
    // declare structs and initialise
    struct Point p1;
    struct Point p2 = {};
    struct Point p3 = {11.11, 22};
    struct Point p4 = {.x = 33.33, .y = 44};

    // print components
    printf("p1 = %lf, %i\n", p1.x, p1.y);
    printf("p2 = %lf, %i\n", p2.x, p2.y);
    printf("p3 = %lf, %i\n", p3.x, p3.y);
    printf("p4 = %lf, %i\n", p4.x, p4.y);

    // set components
    p1.x = 55.55;
    p1.y = 66;
    p2.x = 77.77;
    p2.y = 88;

    // print components
    printf("p1 = %lf, %i\n", p1.x, p1.y);
    printf("p2 = %lf, %i\n", p2.x, p2.y);
    printf("p3 = %lf, %i\n", p3.x, p3.y);
    printf("p4 = %lf, %i\n", p4.x, p4.y);
}