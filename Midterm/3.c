#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 512


int main(void) {
	int fdin, fdout;
	char buf[SIZE];

	// Open file dummy for read
	fdin = open("dummy", O_RDONLY);
	// Open file copy for write
	fdout = open("copy", O_CREAT | O_WRONLY | O_TRUNC, 0644);

	int count = 0;

	// while at the end of dummy
	while (count < SIZE) {
		// read dummy onto buf
		read(fdin, (buf+count), 1);

		// print error message if error occurred
		if (buf[count] == -1) {
			perror("Read dummy");
			exit(1);
		}

		// write on copy
		write(fdout, (buf+count), 1);

		count++;
	} 
	
	close(fdin);
	close(fdout);

	return 0;
}
