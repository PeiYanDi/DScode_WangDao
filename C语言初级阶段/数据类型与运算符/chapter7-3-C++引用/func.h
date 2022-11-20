#include <stdio.h>
//C++的引用  &写到形参的位置，这时的操作=main函数中的操作
void modifyNum(int& b) {
	++b;
}
//C语言的指针引用（相对于C++比较麻烦）
void modify_num(int* d) {
	++(*d);
}

void modifyPointer(int *&p) {
	//p 0x005efa54{10} 指针变量
	//&p 指针变量的地址 0x005efa60{0x005efa54{10}}
	//*p 10
	
	(*p)++;//*p=10
}