/*
 *  It's very common to have nested structues; they are introduced by using dot notation.  In the example below we define a
 *  Rectangle structure that contains a pair of Point structs.  We use typedefs throughout to simplify notation.
 * 
 *  You can access an individual nested component with code such as:
 *              r1.topLeft
 * 
 *  for top level components and
 *              r1.topLeft.x
 * 
 *  for lower level components.  In general each dot takes you down one level of nesting.  Note that you can use component
 *  names when initialising:
 *              Rectangle r1 = {.topLeft.x = 0, .topLeft.y = 0, .bottomRight.x = 120, .bottomRight.y = 250};
 * 
 *  or pass all initialisers by position (note the positions of the {}s):
 *              Rectangle r2 = {{0, 0}, {120, 250}};
 */

#include <stdio.h>

typedef struct
{
    int x;
    int y;
} Point;


typedef struct
{
    Point topLeft;
    Point bottomRight;
} Rectangle;

int main()
{
    // use 4 ints to initialise Rectangle
    Rectangle r1 = {.topLeft.x = 0, .topLeft.y = 0, .bottomRight.x = 120, .bottomRight.y = 250};
    Rectangle r2 = {{0, 0}, {120, 250}};

    // use existing Points to initialise Rectangle
    Point tl = {0,0};
    Point br = {120, 250};
    Rectangle r3 = {.topLeft = tl, .bottomRight = br};
    Rectangle r4 = {tl, br};
    
    // print Rectangles
    printf("r1 = %i, %i, %i %i\n", r1.topLeft.x, r1.topLeft.y, r1.bottomRight.x, r1.bottomRight.y);
    printf("r2 = %i, %i, %i %i\n", r2.topLeft.x, r2.topLeft.y, r2.bottomRight.x, r2.bottomRight.y);
    printf("r3 = %i, %i, %i %i\n", r3.topLeft.x, r3.topLeft.y, r3.bottomRight.x, r3.bottomRight.y);
    printf("r4 = %i, %i, %i %i\n", r4.topLeft.x, r4.topLeft.y, r4.bottomRight.x, r4.bottomRight.y);

    // modify structures at run-time
    r1.topLeft.x = 11;
    r1.topLeft.y = 22;
    printf("r1 = %i, %i, %i %i\n", r1.topLeft.x, r1.topLeft.y, r1.bottomRight.x, r1.bottomRight.y);
    
    Point p = {.x = 44, .y = 55};
    r1.bottomRight = p;
    printf("r1 = %i, %i, %i %i\n", r1.topLeft.x, r1.topLeft.y, r1.bottomRight.x, r1.bottomRight.y);
}