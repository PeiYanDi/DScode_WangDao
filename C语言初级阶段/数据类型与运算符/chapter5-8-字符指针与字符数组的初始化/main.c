#include <stdio.h>

int main() {

	char* p = "hello";//���ַ������׵�ַ������pָ�����    ���ɸ���
	char a[10] = "hello";//�ȼ��� strcpy(a,"hello")������a�ж�Ӧ��ջ�ռ���д��
	a[0] = 'H';
	//p[1] = "E";//�����ԶԳ����������ݽ����޸�

	p = "world";
	//a = "world";//�Ƿ�
	puts(a);
	puts(p);
	return 0;
}