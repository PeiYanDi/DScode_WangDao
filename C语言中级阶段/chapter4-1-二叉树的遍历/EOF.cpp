#include<stdio.h>
//int main() {
//	char str[10][10];
//	int i = 0, j=0;
//	//while (scanf_s("%s", str[i]) != EOF)//因为二维数组str，str[i]就代表一维数组的地址，就不用&
//	while ((str[i][j] = getchar()) != '\n')//1.如果输入[1 2 3 4Enter]，会存入--->数字1、空格 空格(for中加入的)、数字2、...、'\n’(Enter)
//		i++;
//	// 2.在黑框中输入时，系统并不知道什么时候到达了“文件末尾“，因此用< Ctrl + Z >组合键，然后按< Enter >键的方式来告诉系统已经到了 EOF，这样系统才会结束 while
//	//while((str[i]=getchar())!='\n')
//	for (int k = 0; k < i;k++) {
//
//		//printf("%s",str[k][j]);
//		//3.这里写入"%s"--->是输出整个str[k]一维数组的所有内容，已经分配但没有存入数据的内存空间，是不允许读取的--->产生报错
//	
//		printf("%c", str[k][j]);
//		if (k != 0)
//			printf(" ");
//	}
//	return 0;
//}