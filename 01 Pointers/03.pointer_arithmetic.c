#include <stdio.h>

/*
 *  We can repeat the previous exercise with both arrays of ints and doubles.  Note that doubles take up more 
 *  bytes than ints, but pointer arithmetic takes this into account.  Furthermore, the pointer can be 
 *  incremented beyond the end of the array (and we print whatever is in that memory location).  The fact 
 *  that C doesn't check this is called:
 *              NO BOUNDS CHECKING
 * 
 *  If we try the same trick with an array of structures we see the pointer gets incremented by the size of
 *  the structure.
 */

struct Point
{
    int x;
    int y;
};

int main(void)
{
    printf("sizeof int = %li\n", sizeof(int));        
    printf("sizeof double = %li\n", sizeof(double));

    printf("\nincrementing int*\n");
    int a[5] = { 100, 200, 300, 400, 500};          // array of 5 ints
    int* pa = &a[0];
    
    for(int i = 0; i < 7; i++)
    {
        printf("pa = %p, *pa = %i\n", pa, *pa);
        pa++;
    }

    printf("\nincrementing double*\n");
    double b[5] = { 1.11, 2.22, 3.33, 4.44, 5.55};  // array of 5 doubles
    double* pb = &b[0];
    
    for(int i = 0; i < 7; i++)
    {
        printf("pb = %p, *pb = %lf\n", pb, *pb);
        pb++;
    }

    printf("\nincrementing struct Point*\n");
    struct Point c[4] = {{.x = 10, .y = 11}, {.x = 20, .y = 21}, {.x = 30, .y = 31}, {.x = 40, .y = 41}};
    struct Point* pc = &c[0];
    struct Point p;
    
    for(int i = 0; i < 7; i++)
    {
        printf("pc = %p, *pc = %i,%i\n", pc, (*pc).x, (*pc).y);
        pc++;
    }
}