#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	double sum = 0;
	char *c;

	// add all arguments to sum
	for (int i = 1; i < argc; i++) {
		sum += strtod(argv[i], &c);
	}
	
	// print result of sum
	printf("%lf\n", sum);

	return 0;
}
