////////////////////////////////////////////////////////////
//
//  Synchronize Threads
//
////////////////////////////////////////////////////////////

#include <threads.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

mtx_t lock;

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
    mtx_t* pLock;
} PARAMS;

int work(void* v) {
    PARAMS* params = (PARAMS*) v;
    random_delay();
    mtx_lock(params->pLock);

    for (int i = 0; i < 25; i++) {
        random_delay();
        printf("%s", params->id);
        fflush(stdout);
    }
    mtx_unlock(params->pLock);

    return 0;
}


int main(void) {

    srand(time(NULL));

    thrd_t t1, t2, t3, t4;
    mtx_t lock1, lock2, lock3, lock4;

    mtx_init(&lock1, mtx_plain);
    mtx_init(&lock2, mtx_plain);
    mtx_init(&lock3, mtx_plain);
    mtx_init(&lock4, mtx_plain);

    thrd_create(&t1, work, (void*) &(PARAMS){"1", &lock1});
    thrd_create(&t2, work, (void*) &(PARAMS){"2", &lock2});
    thrd_create(&t3, work, (void*) &(PARAMS){"3", &lock3});
    thrd_create(&t4, work, (void*) &(PARAMS){"4", &lock4});

    thrd_join(t1, 0);
    thrd_join(t2, 0);
    thrd_join(t3, 0);
    thrd_join(t4, 0);

    printf("\n");
}
