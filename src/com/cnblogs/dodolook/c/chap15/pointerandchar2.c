#include <stdio.h>

int main()
{
int a[] = {6, 60, 600};
int*p =a;

(*p)++;

printf("%d", *p); //7
}