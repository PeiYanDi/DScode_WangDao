/*��ȡһ���ַ������ַ������ܺ��пո񣬽��ַ�����ת��ԭ�����ַ�������ת���ַ�����ͬ��
���0��ԭ�ַ���С����ת���ַ������-1��������ת���ַ������1��
�������� hello����ת����ַ���Ϊ olleh����Ϊhello С�� olleh���������-1

	֪ʶ�㣺
		�ַ�������ͨ���ã��ҵ������ַ�������λstart��end��Ȼ�󽻻���λ�ռ����ݣ��޸ı���
		1.���ַ���ASCII=0 = NULL
		2.�ո�Space��ASCII=20
		3.scanf�����ո�enter��Ϊ������־
		4.gets_s��������ָ��ֻ�лس������gets_s���ܹ�����ո�ġ�
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>//string.h  --->  strcmp();
#define MaxSize 10

void Reverse(char* str, int start, int end) {//������֮��Ӧ��str��ҲӦ����char*���͵ģ�
	while (start < end) {
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++; end--;
	}
}

int main() {
	char str[MaxSize];//str������������õ��ַ���
	char old[MaxSize];//old����ʼ���ַ���
	//scanf("%s",str);
	gets_s(str);
	int start=0, end;
	for ( end = 0; end < MaxSize; end++)
	{
		if (str[end]!='\0')
		{
			continue;
		}
		end--;
		break;
	}
	for (int i = 0; i <= end; i++)
	{
		old[i] = str[i];
	}
	Reverse(str,start,end);//�����str--->char*���ͣ�
	int result = strcmp(old, str);
	if (result < 0)

	{
		printf("%d\n", -1);
	}
	else if (result > 0)
	{
		printf("%d\n", 1);
	}
	else {
		printf("%d\n", 0);
	}
	return 0;
}