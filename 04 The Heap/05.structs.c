#include <stdio.h>   
#include <stdlib.h> 

// anonymous typedef
typedef struct
{
    int x;
    int y;
} Point;

int main(void) 
{
    Point* p = malloc(4*sizeof(Point));  // allocates enough for an array of 4 Points
    p[0] = (Point){10, 11}; 
    p[1] = (Point){20, 21}; 
    p[2] = (Point){30, 31}; 
    p[3] = (Point){40, 41}; 
        
    for(int i = 0; i < 4; i++)
    {
        printf("p[%i] = %i,%i\n", i, p[i].x, p[i].y);
    }

    free(p);
}
