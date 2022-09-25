#define _GNU_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	char *cwd;

	// Search for path
	// System automatically allocates memory and return the path 
	cwd = get_current_dir_name();
	printf("cwd = %s\n", cwd);
	// Deallocate memory
	free(cwd);
}
