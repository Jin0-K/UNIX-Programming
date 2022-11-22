#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	FILE *fp;
	int fd[2];
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
			break;
		case 0 : // Child
			close(fd[1]);
			len = read(fd[0], buf, BUFSIZ);
			printf("line: %s\n", buf);
			close(fd[0]);
			break;
		default : // Parent

	pclose(fp);
}

