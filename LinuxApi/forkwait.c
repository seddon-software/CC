#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
  pid_t pid;
  int   status;

  switch ( pid = fork() )
  {
    case -1: perror ("fork failed");
             exit(1);

    case 0:  execlp ( "ls", "ls", "-l", NULL );
			 perror("child exec failed");

	default: 
		if ( wait(&status) > 0 && WIFEXITED(status) )
			printf("Child exited with exit status %d\n", WEXITSTATUS(status));
  }

  return 0;
}
