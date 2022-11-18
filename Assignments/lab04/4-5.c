#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 100

int main(void) {
	pid_t pid;
	int i, status;
	int fd;
	char c;
	char buf[BUFSIZE];
	int size = 0;

	// fork failure
	if ((pid = fork()) < 0) {
		perror("fork");
		exit(1);
	}

	// Parent process
	if (pid > 0) {
		// wait for the child to end
		wait(&status);

		printf("***Contents of 4-5.txt***\n");

		// Open 4-5.txt
		fd = open("4-5.txt", O_RDONLY);
		if (fd == -1) {
			perror("Open 4-5.txt");
			exit(1);
		}
		
		// read 4-5.txt
		size = read(fd, buf, BUFSIZE);
		if (size == -1) {
			perror("Read");
			exit(1);
		}
		buf[size] = '\0';

		// stdout
		printf("%s\n", buf);
		close(fd);
	}

	// Child process
	else {
		printf("***Enter contents for 4-5.txt***\n");

		// stdin
		while ((c=getchar()) != EOF) {
			buf[size++] = c;
			if (size == BUFSIZE) {
				break;
			}
		}
		puts("");

		// Open 4-5.txt
		fd = open("4-5.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd == -1) {
			perror("Open 4-5.txt");
			exit(1);
		}

		// write in 4-5.txt
		if (write(fd, buf, size) != size) {
			perror("Write");
		}
		close(fd);

		// end the process
		exit(3);
	}
	
	return 0;
}
