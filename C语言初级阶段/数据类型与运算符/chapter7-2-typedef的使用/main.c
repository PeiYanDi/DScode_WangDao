#include <stdio.h>

typedef struct student {
	int num;
	char name[20];
	char gender[3];//�����GB2312�ġ��С���ռ�����ֽڣ��������ַ�����ʾ
}stu,*pstu;
typedef int INTEGER;


int main() {

	stu s = {100,"lisi","��"};
	pstu p;
	INTEGER i = 10;
	p = &s;
	printf("i = %d\n", i);
	printf("%d %s %s\n", s.num, s.name, s.gender);
	printf("%d %s %s\n", p->num, p->name, p->gender);
	return 0;
}
/*
stu s ---��  struct student s(�ȼ�)
pstu p ---�� struct *pstu p(�ȼ�)
p���ǽṹ��ָ�����
*/