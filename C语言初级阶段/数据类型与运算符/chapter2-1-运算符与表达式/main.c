#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
/*C语言中，需要导入“stdbool.h”头文件
  C++中，可以直接使用，不需要导入"stdbool.h"头文件

  使用 printf () 打印 bool 时，我们必须使用格式为 %d ，
  因为 bool 值没有特定参数。 由于 bool 比 int 短，因此当在 printf () 语句中传递时，它被提升为 int
*/

int main() {
	int a;
	scanf("%d", &a);
	bool flag = true;
	printf("%b\n", flag);
	return 0;
}