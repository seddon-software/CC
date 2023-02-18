////////////////////////////////////////////////////////////
//
//  Data Integrity
//
////////////////////////////////////////////////////////////

#include <threads.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


long count1;   // unprotected
long count2;

int work(void* v) {
    #define LOOPS 500000
    mtx_t* pLock = (mtx_t*) v;  
    for (int i = 0; i < LOOPS; i++) {
        count1++;
    }
    for (int i = 0; i < LOOPS; i++) {
        mtx_lock(pLock);
        count2++;
        mtx_unlock(pLock);
    }
    return 0;
}

int main(void) {
    #define MAX_THREADS 100
    mtx_t lock;
    mtx_init(&lock, mtx_plain);
    thrd_t thread[MAX_THREADS];

    for(int i = 0; i < MAX_THREADS; i++) {
        thrd_create(&thread[i], work, (void*) &lock);
    }
    for(int i = 0; i < MAX_THREADS; i++) {
        thrd_join(thread[i], 0);
    }

    printf("count1 = %li\n", count1);
    printf("count2 = %li\n", count2);
}
