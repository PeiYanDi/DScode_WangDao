#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
	int num;
	char* p;
	char c;
	scanf("%d", &num);
	//���棬��C++�б���
	p = malloc(num);//malloc()����ռ�ĵ�λ���ֽ�
	//scanf("%c", &c);//�ȼ���getchar();  �����ĸ�������
	//����getchar���Զ���һ�������Ŀհ��ַ���scanf(" ");���Զ���֮ǰ���һ���ǿհ��ַ����ȫ���հ��ַ���	
	getchar();
	//scanf(" ");���Զ���֮ǰ���һ���ǿհ��ַ����ȫ���հ��ַ�
	//���棬��C++�б���
	gets(p);//�����ͨ�������scanfȥ����\n,gets���Ῠס
	fgets(p, num, stdin);//ͨ����׼��������������(C++�в�����)
	puts(p);
	return 0;
}