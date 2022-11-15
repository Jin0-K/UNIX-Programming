#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 100

int main() {
	int status = 0;
	pid_t pid, wpid;
	FILE *file;
	char str[BUFSIZ];

	file = fopen("data.txt", "rw");

	switch(pid=fork()) {
		case -1 :
			perror("fork()");
			exit(1);
			break;

		case 0 : /* child process */
			// get input to write in file
			printf("Enter something to write\n");
			gets(str);

			// write input contents to the file
			fwrite(str, 1, BUFSIZE, file);

			exit(2);

			break;

		default : /* parent process */
			// wait untill child ends
			while ((wpid = wait(&status)) > 0);

			// read the file
			fread(str, 1, BUFSIZE, file);		
		
			// print the contents read from the file
			puts(str);

			break;
	}
	
	fclose(file);

	return 0;
}
