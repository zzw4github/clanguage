#include <string.h>
#include <stdlib.h>

void GetMemory(char* p) 
{ 
    char *pp = malloc(sizeof(char) *10); 
} 

// 二、使用指针做函数参数： 

// 1、有的情况下我们可能需要需要在调用函数中分配内存，而在主函数中使用，而针对的指针此时为函数的参数。此时应注意形参与实参的问题，因为在C语言中，形参只是继承了实参的值，是另外一个量(ps:返回值也是同理，传递了一个地址值(指针)或实数值)，形参的改变并不能引起实参的改变。 

// 2、直接使用形参分配内存的方式显然是错误的，因为实参的值并不会改变，如下则实参一直为NULL: 
int main() 
  { 
               char *str; 
               GetMemory(str); 
	               strcpy(str, "hi"); // str = NULL
	               return 0;
            } 