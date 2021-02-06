#include <stdio.h>
#include <unistd.h>
#include <signal.h>
 
void sig_handler(int signum) {
    signal(SIGALRM, sig_handler); // Register signal handler
    alarm(2);
    printf("in handler\n");
}
 
int main() {
    signal(SIGALRM,sig_handler); // Register signal handler

    alarm(2);  // Scheduled alarm after 2 seconds

    for(int i=1;;i++){
        printf("%d : in main\n",i);
        sleep(1);
    }
}