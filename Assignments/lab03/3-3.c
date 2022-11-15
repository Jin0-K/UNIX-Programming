#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
	int fd;
	char buf[100];
	
	// Open file 3-1.txt
	fd = open("3-1.txt", O_RDONLY);
	if (fd == -1) {
		perror("Open 3-1.txt");
		exit(1);
	}

	// Read the file contents
	int count = 0;
	while (read(fd, (buf+count), 1) != 0) {
		if (buf[count] == -1) {
			perror("Read 3-1.txt");
			exit(1);
		}
		count++;
	}
	buf[++count] = '\0';

	// Close 3-1.txt and open 3-3.txt
	close(fd);
	fd = open("3-3.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1) {
		perror("Open 3-3.txt");
		exit(1);
	}

	// Write in 3-3.txt
	int i = 0;
	while (i < count) {
		write(fd, (buf+i), 1);
		i++;
	}
	
	// Close 3-3.txt
	close(fd);

	return 0;
}
