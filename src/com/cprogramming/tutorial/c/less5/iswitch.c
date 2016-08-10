#include <stdio.h>

void playgame() {
	printf("play game called\n");
}

void loadgame() {
	printf("load game called\n");
}

void playmultiplay() {
	printf("play nultiplay game called\n");
}

int main() {
	int input;

	int flag = 1;
	printf("1. play game\n");
	printf("2. load game\n");
	printf("3. play multiplayer\n");
	printf("4. exit\n");
	printf("selection: \n");
	while(flag) {
	scanf("%d", &input);
	switch(input) {
		case 1:
		    playgame();
		    break;
		case 2:
		    loadgame();
		    break;
		case 3:
		    playmultiplay();
		    break;
		case 4:
		    printf("thanks for playing!\n");
		    flag =0;
		    break;
		default:
		    printf("bad input, quitting!\n");
		    flag = 0;
		    break;
	}
}
	getchar();
}