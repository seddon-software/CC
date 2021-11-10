#include "headers.h"

int createFile(const char* fileName) {
	// create new file with rwx permission
	int fd = open(fileName, O_RDWR|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR|S_IXUSR);
	if (fd < 0) {
		perror(fileName);
		exit(1);
	}
	write(fd, "abcdef", strlen("abcdef"));
	printf("created file %s with file descriptor %i\n", fileName, fd);
	
	lseek(fd, 0, SEEK_SET);  // go to start of file
	char buffer[20] = {0};   // fill with nulls
	int nBytes = read(fd, buffer, 20);
	printf("read %i bytes from %s: %s\n", nBytes, fileName, buffer);
	return fd;
}

int main(void) {
	int fd1 = createFile("data/file1");
	int fd2 = createFile("data/file2");
	int fd3 = createFile("data/file3");
	int fd4 = createFile("data/file4");
	int fd5 = createFile("data/file5");
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	close(fd5);
	system("ls -l data");
	return 0;
}

