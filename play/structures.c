#include <stdio.h>
#include <stdbool.h>

struct Point   // define a new type
{
    int x;
    int y;
};
typedef struct Point Point;  // Point is an alias for struct Point 

void changeOriginalPoint(Point* pPoint) { // work with original
    pPoint->x = 99;
    pPoint->y = 88;
}

void printStructure(Point p) {  // p is a copy of p1 or p2
    printf("%i %i\n", p.x, p.y);
}

int main(void) {
    Point p1;
    Point p2 = {30, 40};
    p1.x = 10;
    p1.y = 20;
    changeOriginalPoint(&p1);
    printStructure(p1);
    printStructure(p2);
    Point p3;
    p3 = p2;            // structure copy
    printStructure(p3);
}