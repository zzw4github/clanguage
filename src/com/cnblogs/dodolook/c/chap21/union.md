我也要学C语言-第二十一章：共用体，类型定义-TYPEDEF
先看看一个问题

　　现在需要定义一种数据类型stu，这个stu可以放学生的姓名，学号，以及成绩，其中成绩的话，一些老师是按照ABCDEF给的，有的老师是按照百分制给的成绩，但是现在我们要求该类型可以如实的反映学生的情况。

　　我们来思考下，用ABCDEF的，我们应该用什么类型呢，应该是用char,因为用的是等级制，所以应该是字符型。而另外一些老师用的百分制，这个理所当然的应该用float.因为分数可能是有小数的。那么现在我们该怎么办呢！

　　我们先来试试看：

```
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
float fScoreEng;//1种成绩表示方式
　 char cScoreEng;//另1种成绩的表示方式
int nTpye;//类型记录
};
int main()
{
struct stStudent stu;

return 0;
}
```
但是仔细思考下，我们存进去了如何读取呢，聪明的你肯定想到再来1个变量，记录类型信息。这样的话就达到目的了。

我们再来看代码：

```
#include "stdio.h"
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
float fScoreEng;
int nVt;
};

int main()
{ 
struct stStudent stu; 
stu.nVt =0;
stu.fScoreEng ='a';//0x61 ---> 97.0f
printf("%c", stu.fScoreEng);//97.0f ---> 0x61
return0;
}
```
这个程序在有两次隐式转换，第一次，'a'的值转换为float存在了fScoreEng.接着又把float型fScoreEng转换为字符型存起来啦！

如果我们不想有这样的隐式转换，我们怎么办呢，那么我们就自己弄啦！

```
#include "stdio.h"
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
float fScoreEng;
int nVt;
};

int main()
{ 
struct stStudent stu; 
stu.nVt =0;
*(char *)&stu.fScoreEng ='a'；
printf("%c", *(char *)&stu.fScoreEng);
return 0;
}
```
这样就好啦！但是再一想，有些老师给的是单精度浮点型，有的是给的双精度的，那怎么呀？！那么我就定义double型。不过这一切还是感觉不是很好啊，那怎么搞定呢！C语言已经为我们准备好了，这个就是共用体。

　　共用体就是把自己所以想定义的数据类型都定义出来，然后选择最大者为内存使用情况，谁最大就放谁。

我们来看看以下代码：





这样就清楚的看到了共用体做了什么事情了。

类型定义-typedef

　　typedef就是把已有的数据类型取个别名。我们来看看代码：

```
typedef int far *LPINT;
typedef WORD near *PWORD;
typedef WORD far *LPWORD;
typedef long far *LPLONG;
typedef DWORD near * PDWORD;
typedef DWORD far *LPWORD;
typedef void far *LPVOID;
typedef CONST void far *LPCVOID;

type int INT;
type unsigned int UINT;
type unsigned int *PUINT;

#ifndef NT_INCLUDED
#include <winnt.h>
#dendif /* NT_INCLUDED */

/* Typed use for passing & returning polymorphic values */
typedef UINT WPARAM;

```

再一个可以利用typedef在进行不同平台的移植。只要重新定义下，就很方便的修改了。

