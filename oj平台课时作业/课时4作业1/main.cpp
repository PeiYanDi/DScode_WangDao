/*
问题：
1.输入一个整型数，判断是否是对称数，如果是，输出yes，否则输出no，不用考虑这个整型数过大，int类型存不下，不用考虑负值；
	例如 12321是对称数，输出yes，124421是对称数，输出yes，1231不是对称数，输出no
2.要求编程判断以字符串的形式给出的对称数，但不能用字符判断的方法。
思路：
1.先将 字符串---》整数
2.思路一：比较左右想对称的数字---》方法很难实现，但很容易想到【易错】
  思路二：把数字左右对调，在与初始数字进行比较
	如何进行对调？
		取余可以得到最右边的数字，整型数做除法可以去掉小数部分
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//将字符串 转化 为整数
int Transform_Char_Int(char* p) {
	int temp, result = 0;
	for (; *p != '\0'; p++) {
		temp = *p - '0';
		result = result * 10 + temp;
	}
	return result;
}

void Decide(int num) {
	int newNum = num;
	int reverseNum = 0;
	do
	{
		reverseNum = reverseNum * 10 + (num % 10);
	} while ((num /= 10) != 0);
	if (newNum == reverseNum)
	{
		printf("yes");
	}
	else
	{
		printf("no");
	}
}

int main() {
	char str[20];
	scanf("%s", str);
	Decide(Transform_Char_Int(str));//这是纯C的写法
	
}