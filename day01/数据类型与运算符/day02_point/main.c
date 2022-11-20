#define _CRT_SECURE_NO_WARNINGS//必须位于首部
#include <stdio.h>

char* print_stack() {
	char c[] = "I am a print_stack";
	puts(c);
	return c;
}

char* print_heap() {
	char* p = (char*)malloc(30);
	strcpy(p, "I am a print_heap");
	puts(p);
	return p;
}

int main() {
	char* p;
	p = print_stack();//栈空间，会随着函数执行的结束而释放
	puts(p);//打印异常
	//char c;
	//scanf("%c", &c);
	p = print_heap();//堆空间，不会随着函数执行的结束而释放(堆空间，动态申请，要动态释放掉；不释放的话，程序运行期间，该堆空间一直存在)
	puts(p);
	free(p);
	return 0;
}