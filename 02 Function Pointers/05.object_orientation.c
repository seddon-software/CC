#include <stdio.h>

/*
 */
typedef struct Point
{
    int x;
    int y;
    void (*display)(struct Point* this);
    void (*moveBy)(struct Point* this, int dx, int dy);
} Point;

void display(Point* this)
{
    printf("Point: %i, %i\n", this->x, this->y);
}

void moveBy(Point* this, int dx, int dy)
{
    this->x += dx;
    this->y += dy;
}

int main(void)
{
    Point p = {.x=10, .y=20, .display=display, .moveBy=moveBy};
    p.display(&p);
    p.moveBy(&p, 1, 2);
    p.display(&p);
}
