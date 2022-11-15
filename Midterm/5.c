#include <stdio.h>
#include <time.h>

int main(void) {
	time_t t;
	struct tm* timeInfo;

	// get time information
	t = time(NULL);	
	timeInfo = localtime(&t);

	// print it like date
	printf("%d. %d. %d (Mon) %d:%d:%d KST\n",
		timeInfo->tm_year + 1900,
		timeInfo->tm_mon + 1,
		timeInfo->tm_mday,
		timeInfo->tm_hour,
		timeInfo->tm_min,
		timeInfo->tm_sec);

	return 0;
}
