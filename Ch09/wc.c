#include <stdio.h>

#define IN 1 // inside a word 
#define OUT 0 // outside a word

// count lines, words, and characters in input
int main(int argc, char *argv[]) {
	int c, nl, nw, nc, state;
	FILE *fp;
	state = OUT;
	nl = nw = nc = 0;

	fp = fopen(argv[1], "r");

	while ((c = fgetc(fp)) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d \n", nl, nw, nc);
}
