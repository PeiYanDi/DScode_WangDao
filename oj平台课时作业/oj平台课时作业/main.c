#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*��1���ܱ�4�����������ܱ�100������2���ܱ�400����*/
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

//��ȡһ��65��122֮�����������Ȼ�����ַ���ʽ������������ȡ��97������ַ�a
int main() {
	int number;
	printf("������65��122֮���������\n");
	scanf("%d",&number);
	if (number >= 65 && number <= 122)
	{
		printf("%c\n", number);
	}
	else
	{
		printf("������Ĳ��ǣ�65��122֮���������");
	}
	
	return 0;
}