#include <stdio.h>

int main() {
	int this_is_a_number;

	printf("enter a number: ");
	scanf("%d", &this_is_a_number);
	printf("you enter %d", this_is_a_number);
	getchar();
	return 0;
}