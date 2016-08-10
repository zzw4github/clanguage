
指向指针的指针到底是什么

　　指针是一种抽象，在计算机中指地址编号，当然你可以把生活中的任何东西进行精心有用的抽象，一个指针在计算机中就相当于地址编号+其对这个地址编号的解释方式。指针变量呢就是1个代号，通过这个代号可以取得指针的这么一个东西，为什么会有变量产生，主要是为了避免程序员直接和地址打交到而产生的变量。指针变量也是变量占内存的，所以指针变量就会它的地址，既然有地址，那么这个地址就可以给另外一个指针变量，那么另外的这个指针变量就叫做指向指针的指针。

变量的直接引用与间接引用

通过变量名叫做直接引用，通过指针对变量的引用叫间接引用

间接引用的两种情况

1，如果在一个指针变量中存放的是一个目标变量的地址叫做一级地址

2，如果在一个指针变量中存放的是指向目标变量的地址的指针变量的地址，那么这个就叫做二级地址。

怎么来理解这2句话呢，就是可以这么比喻。你喜欢1个人，然后在电话本上找到它的号码（指针）然后你就可以打电话去表白啦！这个就是叫一级地址。再如果，你喜欢1个人，但是你没有他的电话号码，但是你知道他妹妹的电话号码，你就可以拿出电话本查询找她妹妹的电话号码（指针）然后通过她妹妹的电话本（指针）最终找到你喜欢的人！也就是说二级指针取内容便得到一级指针，一级指针再取内容就得到了目标变量啦！

注意一个程序指针要是超过了2级，你就该考虑下你的设计是否合理了。

指向指针的指针的例子：

```
void main()
{
    int a =99;
    int*pa =&a;
    int**ppa =&a;
}
```

大家看这个程序正确吗？细心的你一下子就反应过来，这样是绝对不行的，因为类型不匹配呀！会报错啦！

那么再看这个程序：

```
void main()
{
    int a =99;
    int*pa =&a;
    int**ppa = &&a;
}
```
嘿嘿！这样是不是就可以啦！其实啊!这样写也是错误的，因为变量取地址就是一个地址常量，地址常量是无法取地址的呢！我们的取地址符只能对有内存空间的东西啦！

所以正确的应该是这样的：

```
void main()
{
int a =99;
int*pa =&a;
int**ppa =&pa;
}
```
