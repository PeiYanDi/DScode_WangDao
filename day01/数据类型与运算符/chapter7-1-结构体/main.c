#include <stdio.h>

struct student {
	int num;
	char name[20];
	char gender[3];
	int age;
	char address[40];
};
struct point {
	char descripe[20];
	int rank;
};
int main() {
	struct student s1 = { 1,"����","��",23,"�������Ϻ�" };//��---��c4d0(ʮ������)��������һ���ַ���ʾ��Ҫ���ַ�������ʾ
	printf("%d %s %s %d %s\n", s1.num, s1.name, s1.gender, s1.age, s1.address);
	printf("\n");

	struct student* p;
	p = &s1;
	printf("%d %s %s %d %s\n", p->num, p->name, p->gender, p->age, p->address);
	//printf("%s %d\n", p->descripe,p->descripe);
	return 0;
}