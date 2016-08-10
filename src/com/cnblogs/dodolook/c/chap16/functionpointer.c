#include <stdio.h>

/*
指向函数的指针变量定义：类型名 （* 指针变量名） ();
*/

int Max(int x, int y) {
	return x > y ? x : y;
}

int main() {
	int a ;
	int (*p)(int, int) = NULL;
	p = Max;

	a = p(2, 9);
	printf("%d\n", a);
}