#include <stdio.h>

// void error1()
// {
// 	int a = 1;
// 	int *p = &a;
// 	int **pp = &a;
// 	printf("%d\n", a );
// 	printf("*p = %d\n", *p);
// 	printf("**pp = %d\n", **pp);//waring: initialization from incompatible pointer type 运行时程序报错
// }

// void error2()
// {
// 	int a = 1;
// 	int *p = &a;
// 	int **pp = &&a;  //label 'a' used but not defined
// 	printf("%d\n", a );
// 	printf("*p = %d\n", *p);
// 	printf("**pp = %d\n", **pp);
// }

// void test()
// {
// 	int a = 1;
// 	int *p = &a;
// 	int *pp = &p;  //warning: initialization from incompatible pointer type
// 	printf("%d\n", a );
// 	printf("*p = %d\n", *p);
// 	printf("*pp = %d\n", *pp);
// }


int main()
{
	
	// test();
	// error1();
	// error2();
	return 0;
}