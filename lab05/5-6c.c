#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
	int pd, n;
	char buf[80];

	printf("\n====Client====\n");

	// open MYFIFO
	if ((pd = open("./MYFIFO", O_RDONLY)) == -1) {
		perror("open");
		exit(1);
	}

	// read message from server
	write(1, "From Server :", 13);
	while((n = read(pd, buf, 80)) > 0) {
		write(1, buf, n);
	}

	if (n == -1) {
		perror("read");
		exit(1);
	}

	write(1, "\n", 1);
	close(pd);

	return 0;
}
