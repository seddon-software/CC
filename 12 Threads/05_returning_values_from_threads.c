////////////////////////////////////////////////////////////
//
//  ??
//
////////////////////////////////////////////////////////////

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t mutex;

typedef struct {
    long low;
    long high;
} RANGE;

void* sum_of_squares(void* v) {
    RANGE* range = (RANGE*) v;
    long* pSum = (long*) malloc(sizeof(long));
    *pSum = 0;
    for(long i = range->low; i <= range->high; i++) {
        *pSum += i*i;
    }
    return pSum;
}

int main(void) {
    pthread_t t1, t2, t3;
    long *result1;
    long *result2;
    long *result3;

    pthread_create(&t1, 0, sum_of_squares, (void*) &(RANGE){    1,   100 });
    pthread_create(&t2, 0, sum_of_squares, (void*) &(RANGE){  101,  1000 });
    pthread_create(&t3, 0, sum_of_squares, (void*) &(RANGE){ 1001, 10000 });

    pthread_join(t1, (void**)&result1);
    pthread_join(t2, (void**)&result2);
    pthread_join(t3, (void**)&result3);

    long result = *result1 + *result2 + *result3;
    printf("sum of squares = %li\n", result);
}
