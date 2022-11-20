#include <stdlib.h>
//动态分配
#define InitSize 100
typedef int ElemType;

typedef struct {
	ElemType* data;
	int capacity;//动态数组的最大容量
	int length;
}SeqList;

/*
	初始化顺序表，动态分配存储空间
	顺序表L，引用型
*/
void InitSeqList(SeqList &L) {
	L.data = (ElemType*)malloc(sizeof(ElemType) * InitSize);
	//malloc()函数，是在"stdlib.h"头文件中的；需要导入头文件
	L.length = 0;
	L.capacity = InitSize;
}