#include "headers.h"

void doFile(int);

/*
 * Program to emulate functionality of cat, but avoid
 * dumping directories etc.
 */

#define MAXBUF 1024

int main(int argc, char *argv[]) {
	int fd;

	// open the file and then copy its contents to stdout.

	fd = open("headers.h", O_RDONLY, 0);
	if (fd < 0) {  // on failure
		perror(argv[0]);
		exit(1);
	}

	doFile(fd);
	close(fd);

	return 0;

}

/*
 * Function to copy from specified file descriptor to stdout
 */
void doFile(int fd) {
	char buffer[MAXBUF];
	int n;
	struct stat sbuf;

	// before dumping the fd, check it's not a directory
	if (fstat(fd, &sbuf) < 0) {
		perror("stat");
		return;
	}

	if (S_ISDIR(sbuf.st_mode)) {
		printf("Can't dump a directory\n");
		return;
	}

	while ((n = read(fd, buffer, MAXBUF)) > 0) {
		if (write(1, buffer, n) < 0) {
			perror("write to stdout failed");
			exit(1);
		}
	}

	if (n < 0) {
		perror("read from file failed");
		exit(1);
	}
}

