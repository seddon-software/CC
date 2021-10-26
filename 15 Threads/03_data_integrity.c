////////////////////////////////////////////////////////////
//
//  Data Integrity
//
////////////////////////////////////////////////////////////

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
long count1;
long count2;

void* work(void* v) {
    #define LOOPS 500000
    for (int i = 0; i < LOOPS; i++) {
        count1++;
    }
    for (int i = 0; i < LOOPS; i++) {
        pthread_mutex_lock(&lock);
        count2++;
        pthread_mutex_unlock(&lock);
    }
    return 0;
}

int main(void) {
    #define MAX_THREADS 10
    pthread_t thread[MAX_THREADS];

    for(int i = 0; i < MAX_THREADS; i++) {
        pthread_mutex_init(&lock, 0);
    }
    for(int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&thread[i], 0, work, (void*) NULL);
    }
    for(int i = 0; i < MAX_THREADS; i++) {
        pthread_join(thread[i], 0);
    }

    printf("count1 = %li\n", count1);
    printf("count2 = %li\n", count2);
}
