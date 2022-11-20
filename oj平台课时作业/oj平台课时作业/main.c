#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*（1）能被4整除，但不能被100整除（2）能被400整除*/
//int main() {
//
//	int year;
//	scanf("%d",&year);
//	if ((year%4==0 && year%100!=0) || (year%400==0))
//	{
//		printf("yes");
//	}
//	else
//	{
//		printf("no");
//	}
//	return 0;
//}

//读取一个65到122之间的整型数，然后以字符形式输出它，比如读取了97，输出字符a
int main() {
	int number;
	printf("请输入65到122之间的整型数\n");
	scanf("%d",&number);
	if (number >= 65 && number <= 122)
	{
		printf("%c\n", number);
	}
	else
	{
		printf("您输入的不是，65到122之间的整型数");
	}
	
	return 0;
}