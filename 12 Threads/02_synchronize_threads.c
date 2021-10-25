////////////////////////////////////////////////////////////
//
//  Synchronize Threads
//
////////////////////////////////////////////////////////////

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t lock;

#define ONE_SEC 1000*1000*1000

void random_delay()
{
    double delay = (rand() / (double) RAND_MAX) * ONE_SEC;
    struct timespec t;
    t.tv_sec = 0;
    t.tv_nsec = (int) (delay);
    nanosleep(&t, NULL);
}

typedef struct {
    const char* id;
    pthread_mutex_t* pLock;
} PARAMS;

void* work(void* v) {
    PARAMS* params = (PARAMS*) v;
    random_delay();
    pthread_mutex_lock(params->pLock);

    for (int i = 0; i < 25; i++) {
        random_delay();
        printf("%s", params->id);
        fflush(stdout);
    }
    pthread_mutex_unlock(params->pLock);

    return 0;
}


int main(void) {

    srand(time(NULL));

    pthread_t t1, t2, t3, t4;
    pthread_mutex_t lock1, lock2, lock3, lock4;

    pthread_mutex_init(&lock1, 0);
    pthread_mutex_init(&lock2, 0);
    pthread_mutex_init(&lock3, 0);
    pthread_mutex_init(&lock4, 0);

    pthread_create(&t1, 0, work, (void*) &(PARAMS){"1", &lock1});
    pthread_create(&t2, 0, work, (void*) &(PARAMS){"2", &lock1});
    pthread_create(&t3, 0, work, (void*) &(PARAMS){"3", &lock1});
    pthread_create(&t4, 0, work, (void*) &(PARAMS){"4", &lock1});

    pthread_join(t1, 0);
    pthread_join(t2, 0);
    pthread_join(t3, 0);
    pthread_join(t4, 0);

    printf("\n");
}
