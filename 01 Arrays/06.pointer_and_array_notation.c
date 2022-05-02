#include <stdio.h>

/*
 *  There is a very close relationship between arrays and pointers in C.  We begin with a pointer 'p' that points at an array 'a':
 *              int* p = &a[0];
 *
 *  Now, 'a' and 'p' share the following relations:
 *              a   = p   = &a[0] = &p[0]
 *              a+1 = p+1 = &a[1] = &p[1]
 *              a+2 = p+2 = &a[2] = &p[2]
 *              a+3 = p+3 = &a[3] = &p[3]
 *              a+4 = p+4 = &a[4] = &p[4]
 *              a+1 = p+1 = &a[1] = &p[1]
 * 
 *  and further:
 *              *a     = *p     = a[0] = p[0]
 *              *(a+1) = *(p+1) = a[1] = p[1]
 *              *(a+2) = *(p+2) = a[2] = p[2]
 *              *(a+3) = *(p+3) = a[3] = p[3]
 *              *(a+4) = *(p+4) = a[4] = p[4]
 * 
 *  All this shows that at run-time the array and pointer notation are indistinguishable.  The above relations can be sumarised by:
 *              *(a+i) = a[i] = *(p+i) = p[i]
 * 
 *  and if you apply an & to these relations:
 *              &*(a+i) = &a[i] = &*(p+i) = &p[i]
 * 
 *  which because & and * cancel each other out, become
 *              a+i = &a[i] = p+i = &p[i]
 *  
 *  However, arrays and pointers are different at complile time; arrays allocate storage for the array components and its name acts 
 *  like a pointer, whereas pointers don't allocate any additional storage.  You will also find that the array name behaves as a 
 *  constant pointer. 
 */

int main(void)
{
    int a[] = {10, 20, 30, 40, 50};
    int* p = &a[0];

    // a is the same as &a[0]
    printf("'a' = %p\n", a);
    printf("'&a[0]' = %p\n", &a[0]);
            
    // dereference arrays using pointer notation
    printf("*a     = %i\t", *a);
    printf("*(a+1) = %i\t", *(a+1));
    printf("*(a+2) = %i\t", *(a+2));
    printf("*(a+3) = %i\t", *(a+3));
    printf("*(a+4) = %i\n", *(a+4));

    // dereference pointers using pointer notation
    printf("*p     = %i\t", *p);
    printf("*(p+1) = %i\t", *(p+1));
    printf("*(p+2) = %i\t", *(p+2));
    printf("*(p+3) = %i\t", *(p+3));
    printf("*(p+4) = %i\n", *(p+4));

    // dereference pointers using array notation
    printf("p[0]   = %i\t", p[0]);
    printf("p[1]   = %i\t", p[1]);
    printf("p[2]   = %i\t", p[2]);
    printf("p[3]   = %i\t", p[3]);
    printf("p[4]   = %i\n", p[4]);

    // dereference arrays using array notation
    printf("a[0]   = %i\t", a[0]);
    printf("a[1]   = %i\t", a[1]);
    printf("a[2]   = %i\t", a[2]);
    printf("a[3]   = %i\t", a[3]);
    printf("a[4]   = %i\n", a[4]);
}
