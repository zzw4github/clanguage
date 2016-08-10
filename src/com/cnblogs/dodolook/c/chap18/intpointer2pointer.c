#include <stdio.h>

void main() {
	int a = 99;
	int *pa = &a;
	int **ppa = &pa;

	printf("%08x\r\n", a);
	printf("%08x\r\n", pa);
	printf("%08x\r\n", *pa);
	printf("%08x\r\n", ppa);
	printf("%08x\r\n", *ppa);
	printf("%08x\r\n", **ppa);

	/*
第一个printf语句 a，这个大家都知道啦，输出肯定是63啊，因为十进制99，十六进制就是63啊！

第二个printf语句 pa, pa是不是就代表0x0012ff40啊呵呵！一个变量的本质就是避免程序员和地址打交到啦！04的话就是0012ff44啦！对吧！

第三个printf语句 *pa, *pa就是第二句中的0012ff44取内容啊，当然就是63啦！

第四个printf语句 ppa, ppa呢！通过前面的笔记一看就知道它显示出的值是0012ff40啦！

第五个printf语句，*ppa, *ppa呢！唉！现在看来真是太简单了，显示出0012ff44

第六个printf语句,**ppa, **ppa呢就是0012ff44再取内容嘛！63啦！
	*/

}