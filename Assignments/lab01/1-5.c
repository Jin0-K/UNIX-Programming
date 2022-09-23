#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int i, sum = 0;
	
	// atoi converts string to integer	
	for (i = 1; i < argc; i++) {
		sum += atoi(argv[i]);
	}
	
	printf("%d\n", sum);
	return 0;
}
