#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
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
	static int parent = 1;

	// fork failure
	if ((pid = fork()) < 0) {
		perror("fork");
		exit(1);
	}

	// Parent process
	if (pid > 0) {
		// wait until the child is stopped
		waitpid(pid, NULL, WUNTRACED);

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

		// let the child process execute
		parent = 0;

		// resume the child
		kill(pid, SIGCONT);
	}

	// Child process
	else {
		// stop the execution
		raise(SIGSTOP);

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

		parent = 1;
		exit(3);
	}
	
	return 0;
}
