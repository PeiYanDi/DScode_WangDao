#define _CRT_SECURE_NO_WARNINGS//����λ���ײ�
#include <stdio.h>

char* print_stack() {
	char c[] = "I am a print_stack";
	puts(c);
	return c;
}

char* print_heap() {
	char* p = (char*)malloc(30);
	strcpy(p, "I am a print_heap");
	puts(p);
	return p;
}

int main() {
	char* p;
	p = print_stack();//ջ�ռ䣬�����ź���ִ�еĽ������ͷ�
	puts(p);//��ӡ�쳣
	//char c;
	//scanf("%c", &c);
	p = print_heap();//�ѿռ䣬�������ź���ִ�еĽ������ͷ�(�ѿռ䣬��̬���룬Ҫ��̬�ͷŵ������ͷŵĻ������������ڼ䣬�öѿռ�һֱ����)
	puts(p);
	free(p);
	return 0;
}