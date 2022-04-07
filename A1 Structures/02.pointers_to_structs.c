/*
 *  With pointers to structs, C has two different notations.  To dereference a pointer to anything you use *:
 *              *ptr
 * 
 *  However to access the components of the structure we need to use brackets:
 *              (*ptr).x  (*ptr).y  (*ptr).z
 *
 *  This notation is somewhat clumsy, so C allows the following equivalent notation:
 *              (ptr->x  ptr->y  ptr->z
 */

#include <stdio.h>

struct Point
{
    int x;
    int y;
    int z;
};

int main()
{
    // declare struct and initialise
    struct Point p = {.x = 10, .y = 20, .z = 30};

    // declare pointer to struct and initialise
    struct Point* ptr = &p;

    // print components
    printf("p = %i, %i, %i\n", p.x, p.y, p.z);
    printf("p = %i, %i, %i\n", (*ptr).x, (*ptr).y, (*ptr).z);
    printf("p = %i, %i, %i\n", ptr->x, ptr->y, ptr->z);
}