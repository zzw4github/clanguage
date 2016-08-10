#include <stdio.h>

int Max(int x, int y)
{
    return x>y?x:y;
}

int  main()
{
    int a;
    int (*p)(int) = NULL;
    p = (int (*)(int))Max;//其中int (*)(int)这段呢！是一个数据类型，表示一个单参函数的指针，作用是把1个
							//双参函数的地址强制说成是1个单参函数的地址。

    a = ((int (*)(int, int))p)(2, 9);//然后我们调用时候不行啊，因为参数不对，所以又要转换回来！
    printf("%d\n", a);
    return 0;
    // 指针变量等于一个函数的入口地址，所以它们做加减运算是无意义的

}