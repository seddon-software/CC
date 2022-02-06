#include <stdio.h>
#include <stdlib.h>

/*
 *  Sometimes it's necessary to expand an array on the heap.  The best way to do this is to use realloc.  This is because the
 *  runtime may need to move the array within the heap to find enough space for the expanded array.  Realloc will automatically
 *  reinitialize those items present before the move.
 */
 
int main(void)
{
    int *pa = malloc(10 * sizeof *pa); // allocate an array of 10 int
    if(pa) {
        printf("%zu bytes allocated. Storing ints: ", 10*sizeof(int));
        for(int n = 0; n < 10; ++n) {
            printf("%d ", pa[n] = n);
        }
        fflush(stdout);
    }
 
    int *pb = realloc(pa, 1000000 * sizeof *pb); // reallocate array to a larger size
    if(pb) {
        printf("\n%zu bytes allocated, first 10 ints are: ", 1000000*sizeof(int));
        for(int n = 0; n < 10; ++n) {
            printf("%d ", pb[n]); // show the array
        }
        fflush(stdout);
        free(pb);
    } else { // if realloc failed, the original pointer needs to be freed
        free(pa);
    }
}