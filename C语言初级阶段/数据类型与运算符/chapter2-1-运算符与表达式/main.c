#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
/*C�����У���Ҫ���롰stdbool.h��ͷ�ļ�
  C++�У�����ֱ��ʹ�ã�����Ҫ����"stdbool.h"ͷ�ļ�

  ʹ�� printf () ��ӡ bool ʱ�����Ǳ���ʹ�ø�ʽΪ %d ��
  ��Ϊ bool ֵû���ض������� ���� bool �� int �̣���˵��� printf () ����д���ʱ����������Ϊ int
*/

int main() {
	int a;
	scanf("%d", &a);
	bool flag = true;
	printf("%b\n", flag);
	return 0;
}