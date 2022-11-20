#include <stdio.h>

typedef struct student {
	int num;
	char name[20];
	char gender[3];//这里的GB2312的“男”，占两个字节，不能用字符来表示
}stu,*pstu;
typedef int INTEGER;


int main() {

	stu s = {100,"lisi","男"};
	pstu p;
	INTEGER i = 10;
	p = &s;
	printf("i = %d\n", i);
	printf("%d %s %s\n", s.num, s.name, s.gender);
	printf("%d %s %s\n", p->num, p->name, p->gender);
	return 0;
}
/*
stu s ---》  struct student s(等价)
pstu p ---》 struct *pstu p(等价)
p：是结构体指针变量
*/