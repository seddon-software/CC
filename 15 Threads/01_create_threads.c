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

#include <threads.h>
//#include <pthread.h>
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

int work(void* v) {
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

    thrd_t t1, t2, t3, t4;

    thrd_create(&t1, work, (void*) "1");
    thrd_create(&t2, work, (void*) "2");
    thrd_create(&t3, work, (void*) "3");
    thrd_create(&t4, work, (void*) "4");

    int result1, result2, result3, result4;
    thrd_join(t1, &result1);
    thrd_join(t2, &result2);
    thrd_join(t3, &result3);
    thrd_join(t4, &result4);
    printf("\n");
}
