#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
	int pd;
	char str[] = "Pipe Test";

	printf("\n====Server====\n");

	// make MYFIFO
	if (mkfifo("./MYFIFO", S_IFIFO | 0666) == -1) {
		perror("mknod");
		exit(1);
	}

	if ((pd = open("./MYFIFO", O_WRONLY)) == -1) {
		perror("open");
		exit(1);
	}

	// write message
	if (write(pd, str, strlen(str)+1) == -1) {
		perror("write");
		exit(1);
	}
	close(pd);

	printf("To Client : %s\n", str);

	return 0;
}
