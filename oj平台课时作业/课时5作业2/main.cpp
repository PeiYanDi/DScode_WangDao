/*读取一个字符串，字符串可能含有空格，将字符串逆转，原来的字符串与逆转后字符串相同，
输出0，原字符串小于逆转后字符串输出-1，大于逆转后字符串输出1。
例如输入 hello，逆转后的字符串为 olleh，因为hello 小于 olleh，所以输出-1

	知识点：
		字符串的普通逆置：找到逆置字符串的首位start、end，然后交换首位空间内容，修改变量
		1.空字符的ASCII=0 = NULL
		2.空格Space的ASCII=20
		3.scanf：将空格、enter作为结束标志
		4.gets_s：的输入分割符只有回车，因此gets_s是能够读入空格的。
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>//string.h  --->  strcmp();
#define MaxSize 10

void Reverse(char* str, int start, int end) {//这里与之对应的str，也应该是char*类型的；
	while (start < end) {
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++; end--;
	}
}

int main() {
	char str[MaxSize];//str用来最后存放逆置的字符串
	char old[MaxSize];//old存放最开始的字符串
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
	Reverse(str,start,end);//这里的str--->char*类型；
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