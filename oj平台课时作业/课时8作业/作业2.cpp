/*
使用C++的引用，注意提交时把代码选为C++；在主函数定义字符指针 char *p,
然后在子函数内malloc申请空间（大小为100个字节），通过fgets读取字符串，然后在主函数中进行输出；
要求子函数使用C++的引用，注意在C++中从标准输入读取字符串，需要使用fgets(p,100,stdin)
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

void modify(char* &p) {
	 p = (char*)malloc(sizeof(char) * MaxSize);//此时的p--->char*
	 fgets(p,100,stdin);//fgets(Buffer,MaxCount,Stream);
}
//C++中，传入主函数一级指针的形式
int main() {
	char* p;
	modify(p);
	printf("%s",p);
	return 0;
}