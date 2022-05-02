/*
 *  Functions can return structures.  It is important to return structures by copy; all variables defined in the function (i.e. in the
 *  function's stack frame) will be destroyed immediately at the end of the function, except the return value.  When returning by copy,
 *  the compiler delays destroying the struct until after it is assigned in the calling program.  Thus when we write:
 *              return p;
 *  
 *  the compiler ensures a temporary copy is made of p which is not destroyed until after it is assigned to q: 
 *              q = reflect_point_in_xaxis(p);
 *  
 *  Recall that the function:
 *              Point reflect_point_in_xaxis(Point p)
 * 
 *  dictates that p is passed by copy as opposed to passed by pointer (no *) and the function returns by copy (again no *).  The 
 *  alternative would be to work with pointers (see next example).
 */

#include <stdio.h>

typedef struct
{
    int x;
    int y;
} Point;

Point reflect_point_in_xaxis(Point p)  // pass by copy and return by copy
{
    p.x = -p.x;
    return p;
}

int main()
{
    Point p = {.x = 100, .y = 200};
    printf("Point p = {%i,%i}\n", p.x, p.y);    

    // reflect Point
    Point q;
    q = reflect_point_in_xaxis(p);

    // this generates an exception
    printf("Reflected Point = {%i,%i}\n", q.x, q.y);
}

