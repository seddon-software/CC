#include <stdio.h>

/*
 *  You can have pointers to structures.  The main point of interest is that there are two different, but equivalent
 *  syntaxes to access a structure from a pointer.  Consider:
 *                  (*ptr).x = 10;
 *                  (*ptr).y = 20;
 * 
 *  The pointer is dereferenced with the * (*ptr) and then the dot operator is used to access the components (a and y).
 *                 (*ptr).x = 10;
 *                 (*ptr).y = 20;
 * 
 *  While this syntax is straightforward it has to be said that is a little awkward to have to use () and the dot.  As an 
 *  alternative you can use the -> operator:
 *                  ptr->x = 30;
 *                  ptr->y = 40;
 * 
 *  Note: recent changes to the C standard allow you to specify the component names when initializing a structure.  Thus the 
 *  following are equivalent:
 *                  struct Point p = {.x = 1, .y = 2};
 *                  struct Point p = {1, 2};
 * 
 */

struct Point
{
    int x;
    int y;
};

void print(struct Point p)
{
    printf(".x=%i, .y=%i\n", p.x, p.y);
}

int main(void)
{
    struct Point p = {.x = 1, .y = 2};
    struct Point q = {.x = 3, .y = 4};
    struct Point* ptr;

    ptr = &p;
    (*ptr).x = 10;
    (*ptr).y = 20;
    print(p);

    ptr = &q;
    ptr->x = 30;
    ptr->y = 40;
    print(q);
}