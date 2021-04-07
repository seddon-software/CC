#include "headers.h"

int main()
{
  pid_t pid;

  pid = fork();

  switch (pid)
  {
    case -1: perror ("fork failed");
             exit(1);
    case 0:  execlp ( "ls", "ls", "-l", NULL );
			 perror("child exec failed");
	default: execlp ( "ps", "ps", "-f", NULL );
			 perror ("exec failed");
  }

  return 0;
}
