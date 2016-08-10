#include <stdio.h>

int main() {
	int age;

	printf("enter your age: ");
	scanf("%d", &age);
	if(age < 100) {
		printf("you are pretty young!\n");
	}else{
		printf("you are old\n");
	}
	return 0;
}