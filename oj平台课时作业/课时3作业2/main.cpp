/*
��ȡһ�����������ַ������������ֱ𵽱���i��j��k�У�
Ȼ��i��j��kֱ����Ӳ������С���������λС����
���ÿ�������ĸ�������С�����ֳ�������λ
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int i;
	char j;
	float k;
	scanf("%d %c %f",&i,&j,&k);
	float result = i + j + k;
	printf("%.2f",result);
	return 0;
}