#include <stdio.h>

int mult(int x, int y);

int main() {
	int x;
	int y;

	printf("please input two numbers to be multiplied: ");;
	scanf("%d", &x);
	scanf("%d", &y);
	printf("the product of your two numbers is %d\n", mult(x, y) );
	getchar();
}

int mult (int x, int y) {
	return x + y;
}