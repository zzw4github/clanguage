#include <stdio.h>

int main() {
	int x = 0;

	while(x < 10) {
	    printf("%d\n", x);
	    x++;
	}

	do {
		printf("%d\n", x);
		x++;
	}while(x <20);
	getchar();
}