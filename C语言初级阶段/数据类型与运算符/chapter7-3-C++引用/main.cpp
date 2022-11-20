#include "func.h"

int main() {
	int a;
	a = 10;
	modifyNum(a);
	printf("%d\n", a);

	int c = 10;
	modify_num(&c);
	printf("%d\n", c);
	

	int* p1 = NULL;
	int q = 10;
	p1 = &q;
	/*
	p1 0x005efa54{10} 指针变量
	&p1 0x005efa60{0x005efa54{10}} 指针变量的地址
	q 10
	&q 0x005efa54{10}  指针
	*/
	modifyPointer(p1);
	printf("%d\n", *p1);
	return 0;

}