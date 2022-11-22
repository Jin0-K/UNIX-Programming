#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	int fd[2];
	pid_t pid;
	char buf[BUFSIZ];
	int len, status;

	if (pipe(fd) == -1) {
		perror("pipe");
		exit(1);
	}

	switch(pid = fork()) {
		case -1 :
			perror("fork");
			exit(1);
		case 0 : // Child
			close(fd[1]);
			write(1, "Child Process: ", 15);
			len = read(fd[0], buf, BUFSIZ);
			write(1, buf, len);
			close(fd[0]);
			break;
		default : // parent
			close(fd[0]);
			write(fd[1], "Test Message\n", 14);
			close(fd[1]);
			waitpid(pid, &status, 0);
			break;
	}
}
