#include <stdio.h>

#define IN scanf
#define OUT printf
#define N 2

int main() {
	int i = 0;
	char name[N][20];
	long num[N];

	OUT("please input name and ID: \n");

	for(i = 0; i < N; i++) {
		IN("%s", name[i]);
		IN("%ld", &num[i]);
	}

	for(i = 0; i < N; i++) {
		OUT("%s\t", name[i]);
		OUT("%ld\n", num[i]);
	}
}