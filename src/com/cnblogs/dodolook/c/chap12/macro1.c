#include <stdio.h>

#define PI 3.14159
#define L(r) 2 * PI * (r)
#define S(r) PI * (r) * (r)

int main() {
	int i = 5;
	printf("%f\n", S(i));
}