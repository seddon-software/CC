#include <stdio.h>
#include <stdlib.h>

struct Point
{
	int x;
	int y;
};

typedef struct Point Point;

Point* AllocateStructure()
{
	Point* p = malloc(sizeof(Point));
	p->x = 100;
	p->y = 200;
	return p;
}

void UseStructure(Point* p)
{
	printf("%i %i \n", p->x, p->y);
}

void DeallocateStructure(Point* p)
{
	free(p);
}

int main()
{
	Point* q;
	q = AllocateStructure();
	UseStructure(q);
	DeallocateStructure(q);
}


