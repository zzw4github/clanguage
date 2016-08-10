#include <stdio.h>

void main()
{
   char*aStringA[]=
   {
      "I'm not afraid to take a stand",
      "We'll walk this road together, through the storm",
      "Whatever weather, cold or warm"
   };

  char aStringB[][60]=
   {
      "I'm not afraid to take a stand",
      "We'll walk this road together, through the storm",
      "Whatever weather, cold or warm"
   };

}

/*

1对于这个例子呢！如何输出的话。2个结果都一样的！但是它们有什么区别呢？！大家好好回忆下我之前的笔记，然后我们做以下区别的总结：

1，第一个数组字符串在常量区，第二个数组字符串在栈区。

2，第一个数组的长度是12字节，第二个数组长度是180字节。

3，第一个数组就像高级语言的变长数组，第二个数组就相当于定长数组拥有很快的寻址能力

4，第一个数组做元素交换很方便，只需要交换指针。第二个数组做交换就得把整个元素都抄下来然后交换*/