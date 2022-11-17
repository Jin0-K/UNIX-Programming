#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define CHILD_NUM 3

void fork3Child(pid_t *pid);
void printPID();

int main(void) {
	pid_t pid[CHILD_NUM];

	fork3Child(pid);

	return 0;
}

// fork 3 child with array of size 3
void fork3Child(pid_t *pid) {
	*pid = fork();
	if (*pid == 0) {
		printPID();
	}
	else {
		*(pid+1) = fork();
		if (*(pid+1) == 0) {
			printPID();
		}
		else {
			*(pid+2) = fork();
			if (*(pid+2) == 0) {
				printPID();
			}
		}
	}
}

// print PID and PPID
void printPID() {
	printf("\nMy pid is %d and ppid is %d", (int)getpid(), (int)getppid());
}
