#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int x;
	int y;
} Point;

typedef struct Cell
{
	Point p;
	struct Cell* next;
} Cell;

Cell* createList()
{
	Cell* ptr = malloc(sizeof(Cell));
	ptr->p.x = -1;
	ptr->p.y = -1;
	ptr->next = NULL;
	return ptr;
}

void append(Cell* ptr, Point p)
{
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = malloc(sizeof(Cell));
	// overwrite end marker
	ptr->p.x = p.x;
	ptr->p.y = p.y;

	// fill in end marker
	ptr = ptr->next;
	ptr->p.x = -1;
	ptr->p.y = -1;
	ptr->next = NULL;
}

int main()
{
	Cell* head = NULL;
	Point q;

	head = createList();
	q.x = 100;
	q.y = 200;
	append(head, q);
	q.x = 101;
	q.y = 201;
	append(head, q);
	q.x = 102;
	q.y = 202;
	append(head, q);
	return 0;
}
