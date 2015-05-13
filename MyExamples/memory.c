#include <stdio.h>
#include <stdlib.h>

struct Point
{
	int x;
	int y;
};

typedef struct Point Point;

Point global;

int main()
{
	{
		Point local;
	}
	// other code
	Point* p = malloc(sizeof(Point));
}

