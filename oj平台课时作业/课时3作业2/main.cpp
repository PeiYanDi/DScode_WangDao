/*
读取一个整型数，字符，浮点数，分别到变量i，j，k中，
然后将i，j，k直接相加并输出，小数点后保留两位小数，
不用考虑输入的浮点数的小数部分超过了两位
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