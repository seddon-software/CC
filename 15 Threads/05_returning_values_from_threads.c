////////////////////////////////////////////////////////////
//
//  ??
//
////////////////////////////////////////////////////////////

#include <threads.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

mtx_t mutex;

typedef struct {
    long low;
    long high;
    long* pResult;
} RANGE;

int sum_of_squares(void* v) {
    RANGE* range = (RANGE*) v;
    // long* pSum = (long*) malloc(sizeof(long));
    // *pSum = 0;
    for(long i = range->low; i <= range->high; i++) {
        *range->pResult += i*i;
    }
//    int result = *pSum;
//    free(pSum);
    return 0;
}

int main(void) {
    thrd_t t1, t2, t3;
    long* pResult1 = malloc(sizeof(long));
    long* pResult2 = malloc(sizeof(long));
    long* pResult3 = malloc(sizeof(long));
    *pResult1 = *pResult2 = *pResult3 = 0;

    thrd_create(&t1, sum_of_squares, (void*) &(RANGE){    1,   100, pResult1 });
    thrd_create(&t2, sum_of_squares, (void*) &(RANGE){  101,  1000, pResult2 });
    thrd_create(&t3, sum_of_squares, (void*) &(RANGE){ 1001, 10000, pResult3 });

    thrd_join(t1, 0);
    thrd_join(t2, 0);
    thrd_join(t3, 0);

    long result = *pResult1 + *pResult2 + *pResult3;
    printf("sum of squares = %li\n", result);
    free(pResult1);
    free(pResult2);
    free(pResult3);
}
