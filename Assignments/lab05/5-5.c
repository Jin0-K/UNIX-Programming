#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
	int pd[2];
	pid_t pid;
	char str[] = "parent sends Pipe Test";
	char buf[BUFSIZ];
	int len, status;

	if (pipe(pd) == -1) {
		perror("pipe");
		exit(1);
	}

	write(pd[1], str, strlen(str));
	printf("%d writes %s to the pipe.\n", (int)getpid(), str);

	switch(pid = fork()) {
		case -1 :
			perror("fork");
			exit(1);
			break;

		case 0 : // child process
			len = read(pd[0], buf, BUFSIZ);
			printf("%d reads %s from the pipe.\n", (int)getpid(), buf);
			break;
		
		default : // parent process
			wait(&status);
			break;
	}

	close(pd[0]);
	close(pd[1]);

	return 0;
}
