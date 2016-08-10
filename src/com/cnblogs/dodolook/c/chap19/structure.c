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
   struct stDate WoW;
   float fScore[3];
};
int main()
{
   struct stStudent stu={
      "dodolook",
      {
      1981,
      7,
      7},
      {
         100,
         99,
      }
   };

   printf(stu.szName);
   return 0;
}

/*
嘿嘿！挺好玩吧！嵌套的时候一定要注意1个原则，无论如何去嵌套！只要能sizeof求出大小的，
随便你怎么去嵌套，不能sizeof求出大小的就不能嵌套!原因是如果不能sizeof求出大小的结构体，编译器无法给其大小！

　　现在我们再思考一个问题！如果要把结构体初始化为全0，怎么办呢！其实很简单了，就是给结构体1个0就可以了啊。
注意不要什么都不给哦，什么都不给的时候，是一个不确定的值。
*/