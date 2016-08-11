#include <stdio.h>

struct stDate
{
int nYear;
int nMonth;
int nDay;
};
struct stStudent
{
char szName[64];
char Sex;
struct stDate WoW;
float fScore[3];
};
int main()
{
struct stStudent stu;
printf("%d", (int)stu.fScore - (int)&stu);//warning: cast from pointer to integer of different size
return 0;
}