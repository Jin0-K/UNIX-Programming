#include <sys/msg.h>
#include <stdlib.h>
#include <stdio.h>

struct mymsgbuf {
	long mtype;
	char mtext[80];
};

int main() {
	struct mymsgbuf inmsg;
	key_t key;
