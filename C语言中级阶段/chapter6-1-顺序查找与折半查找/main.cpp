#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int ElemType;
typedef struct {
	ElemType* elem;//整型指针
	int TableLen;
}Sequenct_Search_Table;

void ST_Init(Sequenct_Search_Table& ST, int len) {
	ST.TableLen = len + 1;//多申请一个位置，为了存哨兵
	ST.elem = (ElemType*)malloc(sizeof(ElemType) * ST.TableLen);
	srand(time(NULL));//生成随机数
	for (int i = 0; i < ST.TableLen; i++)//为啥这里零号位置也随机了数据，为折半查找服务
	{
		ST.elem[i] = rand() % 100;
	}
}

void ST_Print(Sequenct_Search_Table ST) {
	for (int i = 0; i < ST.TableLen; i++)
	{
		printf("%3d", ST.elem[i]);
	}
	printf("\n");
}

int Search_Seq(Sequenct_Search_Table ST, ElemType key) {
	for (int i = 0; i < ST.TableLen; i++)
	{
		if (ST.elem[i] == key) {
			return i+1;//这里返回的值，是从1开始的，所以可以return 0;
		}
	}
	return 0;
}

void BubbleSort(Sequenct_Search_Table ST) {
	for (int i = 0; i < ST.TableLen - 1; i++)//比较了（ST.TableLen-1）轮，11-1=10轮
	{
		for (int j = ST.TableLen - 1; j > 0; j--)
		{//从最后往前两两比较
			if (ST.elem[j] < ST.elem[j-1]) {
				ElemType temp = ST.elem[j - 1];
				ST.elem[j - 1] = ST.elem[j];
				ST.elem[j] = temp;
			}
		}
	}
}

int BinarySearch(Sequenct_Search_Table ST, ElemType key) {
	int low = 0, high = ST.TableLen - 1, mid;
	while (low<=high)//low > high 跳出循环的条件
	{
		mid = (low + high) / 2;
		if (key > ST.elem[mid])
			low = mid + 1;
		else if (key < ST.elem[mid])
			high = mid - 1;
		else
			//return mid;//这里返回的值，是从0开始的，不可以return 0;
			return mid + 1;
	}
	return 0;
}

int main() {
	Sequenct_Search_Table ST;
	ElemType key;
	int pos;//存储查询元素的位置
	ST_Init(ST,10);
	ST_Print(ST);
	printf("请输入要搜索的key值\n");
	scanf_s("%d",&key);
	pos = Search_Seq(ST, key);//顺序查找
	if (pos) {
		printf("查找成功，位置为%d\n",pos);
	}
	else {
		printf("查找失败\n");
	}
	BubbleSort(ST);
	ST_Print(ST);
	printf("二分查找，请输入要搜索的key值:\n");
	scanf_s("%d", &key);
	//有序数组，二分查找才有意义
	pos = BinarySearch(ST,key);
	if (pos)
	{
		printf("二分查找,查找成功,位置为 %d\n", pos);
	}
	else {
		printf("二分查找,查找失败\n");
	}
	
	return 0;
}