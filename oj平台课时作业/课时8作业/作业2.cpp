/*
ʹ��C++�����ã�ע���ύʱ�Ѵ���ѡΪC++���������������ַ�ָ�� char *p,
Ȼ�����Ӻ�����malloc����ռ䣨��СΪ100���ֽڣ���ͨ��fgets��ȡ�ַ�����Ȼ�����������н��������
Ҫ���Ӻ���ʹ��C++�����ã�ע����C++�дӱ�׼�����ȡ�ַ�������Ҫʹ��fgets(p,100,stdin)
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

void modify(char* &p) {
	 p = (char*)malloc(sizeof(char) * MaxSize);//��ʱ��p--->char*
	 fgets(p,100,stdin);//fgets(Buffer,MaxCount,Stream);
}
//C++�У�����������һ��ָ�����ʽ
int main() {
	char* p;
	modify(p);
	printf("%s",p);
	return 0;
}