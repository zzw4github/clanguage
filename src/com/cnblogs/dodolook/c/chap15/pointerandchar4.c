#include <stdio.h>
#include <string.h>

void str_cpy(char* pDest, char* pSrc)
{
    while (*pDest++=*pSrc++);
}

int main()
{
    char sz0[32];
    char sz1[32];
    char sz2[] ="Hello world";

    strcpy(sz0, strcpy(sz1, sz2));

    printf("%s\r\n", sz0);
}