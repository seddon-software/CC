#include <stdio.h>
#include <stdlib.h>

typedef struct Point
{
	int x;
	int y;
} Point;

typedef struct Vector
{
	int size;
	int capacity;
	Point* data;
} Vector;

Vector* createVector(int capacity)
{
	Vector* vector = malloc(sizeof(Vector));
	vector->data = malloc(capacity * sizeof(Point));
	vector->size = 0;
	vector->capacity = capacity;
	return vector;
}

void insert(Vector* v, Point p)
{
	int i;
	if(v->capacity == v->size)  // vector is full need to reallocate
	{
		v->capacity *= 2;		// double the capacity
		Point* newData = malloc(v->capacity * sizeof(Point)); // allocate new space
		for(i = 0; i < v->size; i++)  // copy old data to new region
		{
			newData[i] = v->data[i];
		}
		free(v->data);	// release old data
		v->data = newData;	// reset pointer
	}
	v->data[v->size] = p;
	v->size++;
}

void print(Vector* v)
{
	int i;
	for(i = 0; i < v->size; i++)
	{
		printf("[%i,%i]\n", v->data[i].x, v->data[i].y);
	}
}

int main()
{
	Vector* vector = createVector(4);
	Point p1 = { 1, 1 };
	Point p2 = { 2, 2 };
	Point p3 = { 3, 3 };
	Point p4 = { 4, 4 };
	Point p5 = { 5, 5 };
	Point p6 = { 6, 6 };
	insert(vector, p1);
	insert(vector, p2);
	insert(vector, p3);
	insert(vector, p4);
	insert(vector, p5); // this makes it overflow
	insert(vector, p6);
	print(vector);
}


