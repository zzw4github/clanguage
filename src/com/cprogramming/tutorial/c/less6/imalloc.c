#include <stdio.h>
#include <stdlib.h>

int main() {
	int *ptr = (int*)malloc(sizeof(int));

	int *ptr = malloc( sizeof(*ptr) );
	int x;
	ptr = &x;
	scanf("%d", &x);
	printf("your enter: %d\n", x);
	printf("you enter numer: %d\n", *ptr);

	free(ptr);


	int i,n;
	char *buffer;
	printf("str's length: ");
	scanf("%d", &i);

	buffer = (char*)malloc(i + 1);
	if(buffer == NULL) exit(1);

	for(n = 0; n < i; n++) {
		buffer[n] = rand()%26 + 'a';
	}
	buffer[i] = '\0';

	printf("string is: %s\n", buffer);

	free(buffer);

}