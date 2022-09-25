#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/*
struct dirent {
	ino_t	d_ino;
	off_t	d_off;
	unsigned short d_reclen;
	unsigned char d_type;
	char	d_name[256];
}
*/
 
int main() {
	DIR *dp;
	struct dirent *dent;

	// Open current directory
	dp = opendir(".");
	
	// readdir() returns the contents of current directory
	while ((dent = readdir(dp))) {
		printf("Name : %s \t", dent->d_name);
		printf("Inode : %d\n", (int)dent->d_ino);
	}

	closedir(dp);
}	
