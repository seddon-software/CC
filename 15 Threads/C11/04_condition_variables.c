////////////////////////////////////////////////////////////
//
//  Condition Variables
//
////////////////////////////////////////////////////////////

#include <threads.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

mtx_t mutex;
cnd_t flag;


int work(void* v) {
    const char* id = (const char*) v;

    printf("%s waiting for event\n", id);
    mtx_lock(&mutex);
    cnd_wait(&flag, &mutex);
    printf("\t%s proceeding after event\n", id);
    mtx_unlock(&mutex);
    return 0;
}


int main(void) {
    mtx_init(&mutex, mtx_plain);
    cnd_init(&flag);
    thrd_t t1, t2, t3;
    thrd_create(&t1, work, (void*) "1");
    thrd_create(&t2, work, (void*) "2");
    thrd_create(&t3, work, (void*) "3");

    printf("... main waiting for 10 seconds\n");
    sleep(10);

    printf("... main clearing flag\n");
    cnd_broadcast(&flag);
    thrd_join(t1, 0);
    thrd_join(t2, 0);
    thrd_join(t3, 0);

    printf("\nEnd of main");
}
