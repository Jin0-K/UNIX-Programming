#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void (*hand)(int); // hand is a function that takes int

void sig_handler(int signo) {
	printf("Signal Handler Signal Number : %d \n", signo);
	psignal(signo, "Received Signal");

	hand = signal(SIGINT, SIG_DFL);
}

int main(void) {

	hand = sigset(SIGINT, sig_handler);
	if (hand == SIG_ERR) {
		perror("signal");
		exit(1);
	}
	
	printf("Wait 1st Ctrl+C... : SIGINT\n");
	pause();
	printf("After 1st Signal Handler\n");
	printf("Wait 2nd Ctrl+C... : SIGINT\n");
	pause();
	printf("After 2nd Signal Handler\n");
}
 

