#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/*
 4、根据上述的启发，我们也可以采用指向指针的指针来进行在调用函数中申请，在主函数中应用。
 如下：假设a的地址为ox23，内容为'a'；而str的地址是ox46，内容为ox23；而pstr的地址是ox79，内容为ox46。 
 我们通过调用函数GetMemory，从而将pstr的内容赋给了p，此时p = ox46。
通过对*p(ox23)的操作，即将内存地址为ox23之中的值改为char[100]的首地址，
从而完成了对char* str地址的分配。 
*/

void GetMemory(char** p) 
{ 
    char *p = new char[100]; 
}   

int main() 
{ 
    char a = 'a'; 
    char* str = &a; 
    char** pstr = &str; 
    GetMemory(pstr); 
    strcpy(str, "hi"); 
    printf("%s\n", str);

    free(pstr)
}