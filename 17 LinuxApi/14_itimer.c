#include "headers.h"

char *ticktock[] = { "tick..", "tock.." };

struct itimerval itval = { { 1, 0 }, { 5, 0 } };  // {{repeat interval}, {initial alarm}}

void handler(int sig) {
	static int indx = 0;

	write(1, ticktock[indx], strlen(ticktock[indx]));
	indx++;
	indx = indx % 2;
}

int main(int argc, char *argv[]) {
	struct sigaction sigact;
	sigset_t emptymask;

	sigemptyset(&emptymask);
	sigact.sa_handler = handler;
	sigact.sa_mask = emptymask;
	sigact.sa_flags = 0;

	if (sigaction(SIGALRM, &sigact, NULL) < 0) {
		perror("sigaction");
		exit(1);
	}

	if (setitimer(ITIMER_REAL, &itval, NULL) < 0) {
		perror("setitimer");
		exit(1);
	}

	for (;;)
		sigsuspend(&emptymask);
}
