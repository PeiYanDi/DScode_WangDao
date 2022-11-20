#include <stdio.h>

int main() {

	char* p = "hello";//把字符串的首地址，赋给p指针变量    不可更改
	char a[10] = "hello";//等价于 strcpy(a,"hello")，数组a有对应的栈空间进行存放
	a[0] = 'H';
	//p[1] = "E";//不可以对常量区的数据进行修改

	p = "world";
	//a = "world";//非法
	puts(a);
	puts(p);
	return 0;
}