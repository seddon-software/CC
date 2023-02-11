/*
 *  You might try to make the previous example more efficient by passing the Point by pointer and then to return by pointer.  However,
 *  if you pass by pointer, you will end up modifying the original Point (which you don't want to do).  If you pass by copy, the
 *  original Point will not be compromised.
 *  
 *  By returning by pointer you would expect to make things more efficient.  Unfortunately, this causes a Segmentation Fault.  Why?
 *  Because the pointer will be pointing to the Point copy passed to the routine and this copy will be destroyed at the end of the 
 *  function.  Now when the calling program dereferences the pointer, its memory has already been deallocated; hence the segmentation 
 *  fault.
 * 
 *  To overcome problems like this we need to know how to use the heap; this will be covered later in the course.
 */

#include <stdio.h>

typedef struct
{
    int x;
    int y;
} Point;

Point* reflect_point_in_xaxis(Point copy)  // pass by copy and return by pointer
{
    // reflect point (inverts x component)
    copy.x = -copy.x;
    Point* ptr = malloc(sizeof(Point));
    *ptr = copy;
    return ptr;       // this will generate a segmentation fault
}

int main()
{
    Point p = {.x = 100, .y = 200};

    // reflect Point
    Point* ptr = reflect_point_in_xaxis(p);
    printf("Point p = {%i,%i}\n", p.x, p.y);    
    printf("Reflected Point = {%i,%i}\n", ptr->x, ptr->y);
    free(ptr);
}

