#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>

#define IN 1 // inside a word 
#define OUT 0 // outside a word

// count lines, words, and characters in input
int main(int argc, char *argv[]) {
	char *c;
	int nl, nw, nc, state;
	int fd;
	state = OUT;
	nl = nw = nc = 0;
	caddr_t addr;
	struct stat statbuf;

	fd = open(argv[1], 'r');

	addr = mmap(NULL, statbuf.st_size, PROT_READ, MAP_SHARED, fd, (off_t)0);
	if (addr == MAP_FAILED) {
		perror("mmap");
		exit(1);
	}

	while (*(c = addr++) != EOF) {
		++nc;
		if (*c == '\n')
			++nl;
		if (*c == ' ' || *c == '\n' || *c == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d \n", nl, nw, nc);
}
