/*
���⣺
1.����һ�����������ж��Ƿ��ǶԳ���������ǣ����yes���������no�����ÿ����������������int���ʹ治�£����ÿ��Ǹ�ֵ��
	���� 12321�ǶԳ��������yes��124421�ǶԳ��������yes��1231���ǶԳ��������no
2.Ҫ�����ж����ַ�������ʽ�����ĶԳ��������������ַ��жϵķ�����
˼·��
1.�Ƚ� �ַ���---������
2.˼·һ���Ƚ�������ԳƵ�����---����������ʵ�֣����������뵽���״�
  ˼·�������������ҶԵ��������ʼ���ֽ��бȽ�
	��ν��жԵ���
		ȡ����Եõ����ұߵ����֣�����������������ȥ��С������
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//���ַ��� ת�� Ϊ����
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
	Decide(Transform_Char_Int(str));//���Ǵ�C��д��
	
}