#include <stdio.h>
#include <stdlib.h>

struct Point
{
	int x;
	int y;
};

typedef struct Point Point;

void moveBy(Point* ptr, int dx, int dy);
void print(Point p);
Point* constructor(int x0, int y0);

int main()
{
	Point p1;
	Point p2;
	Point p3;
//	initialize(&p1, 100, 300);
	Point* p = constructor(200, 300);
	print(*p);
	moveBy(p, 1, 1);
	print(*p);
	free(p);
}

Point* constructor(int x0, int y0)
{
	// create AND initialize
	Point* ptr = malloc(sizeof(Point));
	ptr->x = x0;
	ptr->y = y0;
	return ptr;
}

void initialize(Point* ptr, int x0, int y0)
{
	ptr->x = x0;
	ptr->y = y0;
}

void print(Point p)
{
	printf("%i %i \n", p.x, p.y);
}

void moveBy(Point* ptr, int dx, int dy)
{
	(*ptr).x += dx;
	(*ptr).y += dy;
}
