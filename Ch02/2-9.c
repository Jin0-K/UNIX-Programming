#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
	DIR *dp;
	struct dirent *dent;
	long loc;

	dp = opendir(".");

	// telldir() returns the current location of directory stream that parameter points to
	printf("Start Position : %ld\n", telldir(dp));
	while (dent = readdir(dp)) {
		printf("Read : %s -> ", dent->d_name);
		printf("Cur Position : %ld\n", telldir(dp));
	}

	printf("** Directory Position Rewind **\n");
	// rewinddir() moves directory stream location to the start point of directory
	rewinddir(dp);
	printf("Cur Position : %ld\n", telldir(dp));

	printf("** Move Directory Pointer **\n");
	readdir(dp);
	loc = telldir(dp);
	// seekdir() moves offset to the location that readdir() can read next item
	seekdir(dp, loc);
	printf("Cur Position : %ld\n", telldir(dp));

	dent = readdir(dp);
	printf("Read : %s\n", dent->d_name);

	closedir(dp);
}
