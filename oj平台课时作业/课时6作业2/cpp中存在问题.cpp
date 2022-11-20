#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
	int num;
	char* p;
	char c;
	scanf("%d", &num);
	//下面，在C++中报错
	p = malloc(num);//malloc()申请空间的单位是字节
	//scanf("%c", &c);//等价于getchar();  两个哪个都可以
	//区别：getchar可以读走一个残留的空白字符，scanf(" ");可以读走之前最后一个非空白字符后的全部空白字符。	
	getchar();
	//scanf(" ");可以读走之前最后一个非空白字符后的全部空白字符
	//下面，在C++中报错
	gets(p);//如果不通过上面的scanf去消除\n,gets不会卡住
	fgets(p, num, stdin);//通过标准输入流进行输入(C++中不报错)
	puts(p);
	return 0;
}