#include <stdio.h>

void main()
{
int a[5] = {1,2,3,4,5};

for (int *p = a; p < a+5; p++)
{
printf("%p:%d\r\n", p, *p);
}
}