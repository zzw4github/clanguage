#include <stdio.h>

//3、由于通过指针是可以传值的，因为此时该指针的地址是在主函数中申请的栈内存，
// 我们通过指针对该栈内存进行操作，从而改变了实参的值。 


void Change(char *p) 
{ 
   *p = 'b'; 
} 

int main() 
{ 
   char a = 'a'; 
   char* p = &a; 
   Change(p); 
   printf("%c\n", a);           //值a改变! 
   return 0;
}