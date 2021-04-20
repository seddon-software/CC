#include <stdio.h>
#include <stdlib.h>

int z;          // globals initilised to zero
int c[5];       // all set to 0
int w = 9;

int main(void) {
    int x = 100;        // locals allocated on the stack;
    int y;              // filled with garbage
    int a[5];           // filled with garbage
    int b[5] = {};   // i've started so i'll finish

    int* pHeap;         // this is on the STACK
    pHeap = malloc(3*sizeof(int)); // allocate array of 3 ints on HEAP
    pHeap[0] = 22;
    pHeap[1] = 33;
    pHeap[2] = 44;
    pHeap[3] = 55;
    int* p;
    p = malloc(10*sizeof(int));
    p[0] = 99;
    free(pHeap);
    free(p);

}