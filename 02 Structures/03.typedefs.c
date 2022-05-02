/*
 *  When declaring a struct you always have to include the "struct" keyword.  That is unless you use a
 *  typedef.  A typedef introduces an alias for an existing type.  Several forms are available.
 * 
 *  This example introduces the following aliases:
 *              method 1: POINTA is an alias for struct PointA
 *              method 2: POINTB is an alias for struct PointB
 * 
 *  In method 3 we define a typedef of an anonymous struct.  In this case only the typedef is available.
 *  A common trick is to name the typedef with a name you would have given the struct.  This means you can
 *  then declare structs without having to use the struct keyword: 
 *              Point p = {.x = 10, .y = 20, .z = 30};
 */

#include <stdio.h>

// method 1: defining a struct and typedef
struct PointA
{
    int x;
    int y;
    int z;
};
typedef struct PointA POINTA;

// method 2: defining a struct and typedef together
typedef struct PointB
{
    int x;
    int y;
    int z;
} POINTB;

// method 3: defining an anonymous struct and typedef
typedef struct
{
    int x;
    int y;
    int z;
} Point;

int main()
{
    // method 1: you can still use the struct
    struct PointA p1 = {.x = 10, .y = 20, .z = 30};
    POINTA p2 = {.x = 10, .y = 20, .z = 30};

    // method 2: you can still use the struct
    struct PointB q1 = {.x = 10, .y = 20, .z = 30};
    POINTB q2 = {.x = 10, .y = 20, .z = 30};

    // method 3: you can't use the struct because it's anonymous, only the typedef is available
    // but this saves having to use the struct keyword
    Point p = {.x = 10, .y = 20, .z = 30};

    // print components
    printf("p1 = %i, %i, %i\n", p1.x, p1.y, p1.z);
    printf("p2 = %i, %i, %i\n", p2.x, p2.y, p2.z);
    printf("q1 = %i, %i, %i\n", q1.x, q1.y, q1.z);
    printf("q2 = %i, %i, %i\n", q2.x, q2.y, q2.z);
    printf("p = %i, %i, %i\n", p.x, p.y, p.z);
}