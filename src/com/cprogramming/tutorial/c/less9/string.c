#include <stdio.h>

/*
There are several approaches to handling this problem, but probablythe simplest and safest is to use the fgets function, which is declared in stdio.h. 
The prototype for the fgets function is:
char *fgets (char *str, int size, FILE* file);
*/

int main() {
	char string[256];

	printf("please enter a long string:");

	/* notice stdin being passed in */
	fgets(string, 256, stdin );
	printf("you entered a very long string: %s\n", string );
	getchar();
}