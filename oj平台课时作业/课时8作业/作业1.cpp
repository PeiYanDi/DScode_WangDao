/*����һ��ѧ����ѧ�ţ��������Ա��ýṹ��洢��ͨ��scanf��ȡ��Ȼ����ͨ��printf��ӡ���*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MaxSize 30
typedef struct student {
	int stuNumber;
	char name[MaxSize];
	char gender;
};

//int main() {
//	student s;
//	scanf("%d %s %c",&s.stuNumber,s.name,&s.gender);
//	printf("%d %s %c",s.stuNumber,s.name,s.gender);
//	return 0;
//}