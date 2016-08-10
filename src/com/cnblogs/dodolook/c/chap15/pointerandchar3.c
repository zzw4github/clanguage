#include <stdio.h>

void str_cpy(char* pDest, char*pSrc)
{
    while (*pDest++=*pSrc++);
}

int main()
{
    char sz1[32];
    char sz2[] ="Hello world";

    str_cpy(sz1, sz2);

    printf("%s\r\n", sz1);
}

/*
*pSrc++这里的++是后缀，它是最后加1.最后什么时候退出while循环的呢？！
当然我们知道是左值为0的时候。大家是不是觉得这个拷贝字符串的函数写得非常的简洁啊
*/