/*输入N个数（N小于等于100），输出数字2的出现次数；*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MaxSize 10
int main() {
	int total,result=0;
	int data[MaxSize];
	scanf("%d", &total);
	for (int i = 0; i < total; i++)
	{
		scanf("%d", &data[i]);
	}
	for (int i = 0; i < total; i++)
	{
		if (data[i] == 2)
			result++;
	}
	printf("%d",result);
	return 0;
}
