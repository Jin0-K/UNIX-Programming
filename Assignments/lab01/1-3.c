#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	char *str;

	// Create space size of 20 characters	
	//str = malloc(sizeof(char)*20);

	// Copy "Hello" to str
	strcpy(str, "Hello");
	printf("%s\n", str);

	// Copy "Good morning" to str
	strcpy(str, "Good morning");
	printf("%s\n", str);

	free(str);
	return 0;
}
