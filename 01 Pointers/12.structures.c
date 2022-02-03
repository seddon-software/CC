#include <stdio.h>

/*
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