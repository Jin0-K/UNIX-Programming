#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	char *cwd;
	char wd1[BUFSIZ];
	char wd2[10];

	// Get the absoloute address and size of the current directory
	getcwd(wd1, BUFSIZ);
	printf("wd1 = %s\n", wd1);

	// Assign cwd memory size of BUFSIZ
	cwd = getcwd(NULL, BUFSIZ);
	printf("cwd1 = %s\n", cwd);
	// deallocate memory
	free(cwd);

	// System automatically allocate memory for the path and return the address
	cwd = getcwd(NULL, 0);
	printf("cwd2 = %s\n", cwd);
	free(cwd);

	// Allocate smaller buffer than the size of parameter of the getcwd()
	// return NULL if error occurs
	if (getcwd(wd2, 10) == NULL) {
		perror("getcwd");
		exit(1);
	}
}
