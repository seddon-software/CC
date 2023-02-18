////////////////////////////////////////////////////////////
//
//  Create Threads
//
//  notes for vscode:
//  ================
//  To see info about threads (use debug console):
//      -exec info threads
//  To switch to a thread 3:
//      -exec thread 3
//
////////////////////////////////////////////////////////////

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


#define ONE_SEC 1000*1000*1000

void random_delay()
{
    double delay = (rand() / (double) RAND_MAX) * ONE_SEC;
    struct timespec t;
    t.tv_sec = 0;
    t.tv_nsec = (int) (delay);
    nanosleep(&t, NULL);
}

void* work(void* v) {
    for (int i = 0; i < 25; i++) {
        random_delay();
        const char* message = (const char*) v;
        printf("%s", message);
        fflush(stdout);
    }
    return 0;
}

int main(void) {

    srand(time(NULL));

    pthread_t t1, t2, t3, t4;

    pthread_create(&t1, 0, work, (void*) "1");
    pthread_create(&t2, 0, work, (void*) "2");
    pthread_create(&t3, 0, work, (void*) "3");
    pthread_create(&t4, 0, work, (void*) "4");

    pthread_join(t1, 0);
    pthread_join(t2, 0);
    pthread_join(t3, 0);
    pthread_join(t4, 0);

    printf("\n");
}
