我也要学C语言-第二十章：结构体类型变量，结构体数组  　
上节课我们学习到了结构体的定义和初始化，我们在定义学生这个人的时候，姓名最好给char *,学号最好也用char *,因为我们用int表示学号有局限性，因为无法表示带字符的编号啦！因为有些学号不一定是纯数字的啊！成绩呢！就用float型，邮政编码呢！通讯地址呢！char *吧！因为通讯地址有的好长好长，有的又很短呀！呵呵！是不是感觉和以前的知识点都是串起来的呀！以前我们还专门学习过char *呢！

结构体是不允许递归定义的

　　我们来看这个例子：

```
struct person
{
char name[16];
char sex;
int age;
float height;

struct person per;
}
```

大家看这个，我们是无法算出其大小的，这样可不行哦，所以不能结构体递归嵌套定义哦！关于递归的理解，我暂时就是自己调用自己，然后必须有1个出口，不然递归就一直这么递归下去了(看似无限递归，但是计算机内存的栈应该是有限的，在某个时候应该会溢出，我也不知道是不是这样的哦，暂且这样思考，有错的话以后再纠正)。递归的最大优势是可读性好！在后面我会专门学学递归的。

结构体类型变量　　

　　当我们定义了结构体类型后，只是说明了该类型的组成情况，并没有给它分配内存空间，当我们定义了结构体变量的时候，才会为其分配内存空间，就像int本来是不能分配内存空间的，而int a，这个a就有内存空间啦！

　　现在我们来看看，如何定义结构体变量。其实这里上午的学习，已经学习过了，我们我们再回顾下：

```
struct person
{
char name[64];
char sex;
int age;
float height;
};
struct person one;
```
那么这个结构体变量在内存中才排列，我们上午也学习了，那么我再回顾下：它是以我们定义变量的先后顺序依次排列的。然后这个结构体的大小呢，是64+1+2+4.(这里的对齐方式为模1).如果对齐方式是地址模4，那它的大小就不一样啦！一定要注意哦！

结构体变量的另外一种定义方式

　　我们在定义类型的同时定义变量：

 其实两种定义的效果是一样的。嘿嘿！我差点搞忘记啦！还有第3种定义方式：

```
struct person
{
char name[64];
char sex;
int age;
float height;
}one;
```

```

struct
{
char name[64];
char sex;
int age;
float height;
}one;
```
这种方式呢！直接定义结构体类型变量，去掉了类型名！呵呵！切记！这种定义形式和前面的两种方法都不一样的哦，因为没有说明这种结构体类型的名字呀，所以这种方式通常用在不需要再次定义此类型结构体变量的情况下才用。这个就像有些国家的婚姻啊，比如菲律宾，不准离婚呀！

结构体变量的引用

　　结构体变量的引用必须在定义结构体变量后才行。对结构体变量的引用呢可以分为对机构体变量中成员的引用和对整个结构体变量的引用。一般对结构体变量的操作是以成员为单位进行的。

引用的一般形式为：结构体变量名.成员名

.的优先级是所以运算符中优先级最高的哦，一定要记住哦！当遇到某个成员本身又是结构体变量的时候，则必须连续使用成员运算符，就是这个点啦！一直到基本数据类型的时候。结构体变量的每个成员都属于某种数据类型，因此都可以像普通变量一样进行其类型所允许的各种操作。

我们来看一个例子：


这个程序呢！我们来分析下，在main函数里定义了一个结构体person,
结构体person又嵌套定义了一个结构体date.我们来一行一行的分析。

```
#include <stdio.h>

void main()
{
struct person;//定义了一个结构体
{
char name[20];//第一项成员是name,20个字节的数组。
char sex;//定义了性别。

struct date//嵌套定义了一个date类型的结构体，并定义了3个成员.
{
int year;
int month;
int day;
}birthday;//定义了date结构体变量birthday.
float height;//定义了fload类型的身高。
}per;//定义了person结构体类型变量per.
printf("Enter the name:");
gets(per.name);
per.sex='M';
per.birthday.year=1982;
per.birthday.year++;
per.birthday.month=12;
per.birthday.day=15;
per.height=(175+176)/2;
printf("%s%3c%4d%2d%d%7.1f\n",per.name, per.sex,
per.birthday.month, per.birthday.day,per.birthday.year,
per.height );
}
```
操作结构体需要注意的地方

　　我们看下面的程序：

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
struct stDate WoW;
float fScore[3];
};
int main()
{
struct stStudent stu;
stu.szName ="dodolook";
return0;
}
```
这个程序是正确的吗？！其实运行下就知道，会得到一个错误，这个是为什么呢！其实原因是这样的，stu.szName是一个数组名，是常量，所以会出现错误！那么我们怎么为字符数组赋值呢！我们可以这样做，用1个函数，这个函数叫strcpy.如何书写呢！strcpy(stu.szName, "dodolook");这样的话就是正确的了。

对整个结构体变量的引用

　　相同类型的结构体变量之间是可以进行整体赋值的。结构体变量只允许整体赋值，其他操作如输入，输出等必须引用结构体变量的成员。

例如 stu2 = stu;它是把stu成员的值一个一个的抄写过去到stu2.这个其实等价于

memcpy，内存拷贝。如何近进行的内存拷贝呢，我们来看看memcpy的帮助文档：
```
void *memcpy(void *dest, const void *src, size_t count);
```

第一个参数是目的地址，第二个参数是源地址，第三个参数是要拷贝数据的长度，单位是字节。size_t其实就是1个int. 这个函数返回的是void类型的指针，晕，我们以前怎么没见到过这种类型的呀！我们仔细思考下，1个指针带有2个信息，1个是地址信息，1个是如何对这个地址做何种解释的信息。那么void就表示没有信息，这样的话我们对void类型的指针取内容就不行啦！没有信息也是一种信息，就像，没有风格也是一种风格，呵呵！

为什么这里要用void呢？！

　　因为写这个函数的人并不知道你将要拷贝的数据是什么类型。

实例：
```
memcpy(&stu2, &stu, sizeof(stu));
```
结构体数组

　　当我们定义了一种结构体类型以后，就相当于我们可用的变量类型又多了一种了。其实float也是一种结构体，它只是是以位为单位的。我们先来看1个结构体数组的例子：

```
struct person
{
char name[20];
char sex;
int age;
float height;
};
struct person per[3];
```
 哈哈！是不是特好玩！现在我们的数组元素装了个结构体。呵呵！

这里的per是什么呢！per就是person类型的指针常量啦！其实这个和数组差不多了啊！

下面我们来看1个例子程序：

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
};
int main()
{
struct stStudent stu;
printf("%d", (int)stu.fScore - (int)&stu); 
return 0;
}
注：默认是模4地址的。
```
这个例子会打印出多少呢？！我们一起来数数，64+4+12=80 对吧！呵呵。这个例子是不是就可以求出结构体变量的成员到结构体首地址的偏移量呀！对不对呀！很好玩吧！
但是这里有个缺点，必须要用结构体变量，那么我们可以不用一个结构体变量也能求出1个成员的偏移量来吗？！这个问题，到明天的笔记中再说明了。
