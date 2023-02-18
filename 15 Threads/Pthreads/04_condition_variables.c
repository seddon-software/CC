////////////////////////////////////////////////////////////
//
//  Condition Variables
//
////////////////////////////////////////////////////////////

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t mutex;
pthread_cond_t flag;


void* work(void* v) {
    const char* id = (const char*) v;

    printf("%s waiting for event\n", id);
    pthread_mutex_lock(&mutex);
    pthread_cond_wait(&flag, &mutex);
    printf("\t%s proceeding after event\n", id);
    pthread_mutex_unlock(&mutex);
    return 0;
}

int main(void) {
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&flag, NULL);
    pthread_t t1, t2, t3;
    pthread_create(&t1, 0, work, (void*) "1");
    pthread_create(&t2, 0, work, (void*) "2");
    pthread_create(&t3, 0, work, (void*) "3");


    printf("... main waiting for 10 seconds\n");
    sleep(10);

    printf("... main clearing flag\n");
    pthread_cond_broadcast(&flag);
    pthread_join(t1, 0);
    pthread_join(t2, 0);
    pthread_join(t3, 0);

    printf("\nEnd of main");
}
