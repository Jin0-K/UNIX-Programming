#include <sys/sysinfo.h>
#include <stdio.h>

int main() {
	struct sysinfo info;


	sysinfo(&info);

	printf("Total RAM: %ld\n", info.totalram);
	printf("Free RAM: %ld\n", info.freeram);
	printf("Number of processes: %d\n", info.procs);
}
