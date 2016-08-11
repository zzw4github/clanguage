#include <stdio.h>
#include <stdlib.h>

char* GetMomory()
{
	char *p =  malloc(sizeof(char)*10);
	return p;
}

//3、使用堆内存返回指针是正确的，但是注意可能产生内存泄露问题，在使用完毕后主函数中释放该段内存。 

int main()
{
	char *p = GetMomory();
	printf( p, "\n");
	free(p); //防止内存泄露! 
}