#include <stdio.h>

char* GetMemory()
{
	char p[] = "hi";
	//warning: function returns address of local variable 
	return p;
}

/*
一、使用指针做函数返回值：
 
1、当使用指针做为函数的返回值时，主函数处的char *p;将获得调用函数char *pf;的值，即一个地址值，如oxAE72。此时需要我们注意的是该地址值所指向的空间是否存在(即已向操作系统声明注册，不会被释放，即可能被其他操作修改)；

2、使用栈内存返回指针是明显错误的，因为栈内存将在调用结束后自动释放，从而主函数使用该地址空间将很危险。
*/
int main()
{
	char *str = GetMemory(); //出错! 得到一块已释放的内存 

	printf(str,"\n");
}