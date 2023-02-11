/*
 *      VIRTUAL MEMORY MAP
 *      ==================
 * 
 *      0    ┌─────────┐
 *           │  KERNEL │
 *           │  KERNEL │ PROTECTED REGION
 *           │  KERNEL │
 *      2^63 ├─────────┤
 *           │  text   │ code, constants
 *           ├─────────┤
 *           │  data   │ globals
 *           ├─────────┤
 *           │  heap   │ dynamic variables (managed by you: malloc etc) long lifetimes
 *           ├─────────┤
 *           │         │
 *           │         │ HOLE: shared memory (see Linux API)
 *           │         │
 *           ├─────────┤
 *           │  stack  │ local variables (managed by the compiler) short lifetimes
 *      2^64 └─────────┘
 */

#include <stdio.h>   
#include <stdlib.h> 
 
int main(void) 
{
    int *p1 = malloc(4*sizeof(int));  // allocates enough for an array of 4 int
    int *p2 = malloc(sizeof(int[4])); // same, naming the type directly
    int *p3 = malloc(4*sizeof *p3);   // same, without repeating the type name
    
    if(p1) {
        for(int n=0; n<4; ++n) // populate the array
            p1[n] = (n+1)*(n+1);
        for(int n=0; n<4; ++n) // print it back out
            printf("p1[%d] == %d\n", n, p1[n]);
    }

    free(p1);
    free(p2);
    free(p3);
}

