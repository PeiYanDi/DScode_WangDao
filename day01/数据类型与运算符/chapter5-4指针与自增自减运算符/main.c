#include <stdio.h>

int main() {

	int a[3] = { 2,7,8 };
	int* p;
	int j;
	p = a;
	j = *p++;//j = *p, * 与 ++优先级是相等的，运算顺序：从右至左  *(p++)
	printf("a[0]=%d,j=%d,*p=%d", a[0], j, *p);//2,2,7
}