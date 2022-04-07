/*
 *  Structures can be copied.  For small structs this is not much of an overhead, but for large structs this can be a performance
 *  bottleneck if the copying is repeated often.
 * 
 *  Copying usually occurs when you pass a struct to a function.  However, if instead you pass a pointer to a struct, no copying
 *  occurs (efficient).
 */

#include <stdio.h>
#define SIZE 5

typedef struct 
{
  int x;
  int y; 
} Point;

void print_original(Point* ptr)
{
    printf("Point p1 = {%i,%i}\n", ptr->x, ptr->y);
}

void print_copy(Point copy)
{
    printf("copy of Point p1 = {%i,%i}\n", copy.x, copy.y);
}

int main()
{
    Point p1 = {.x = 10, .y = 20};
    printf("Point p1 = {%i,%i}\n", p1.x, p1.y);
    Point p2;

    // copy structures
    p2 = p1;
    printf("Point p2 = {%i,%i}\n", p2.x, p2.y);

    // pass structure to functions
    print_original(&p1);
    print_copy(p1);
}

