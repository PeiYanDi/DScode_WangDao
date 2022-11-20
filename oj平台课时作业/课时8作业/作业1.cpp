/*输入一个学生的学号，姓名，性别，用结构体存储，通过scanf读取后，然后再通过printf打印输出*/
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