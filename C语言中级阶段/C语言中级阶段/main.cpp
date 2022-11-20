#include <stdio.h>
#include "SqList.h"
#include "SeqList.h"


int main() {
	//SqList L;
	//bool ret;//C中是没有bool类型的数据--->加入stdbool.h头文件即可;C++中存在bool类型
	//ElemType del;//要删除的数据
	////手动的在SqList中赋值
	//L.data[0] = 1;
	//L.data[1] = 2;
	//L.data[2] = 3;
	//L.length = 3;
	//ret = ListInsert(L, 2, 60);
	//if (ret)
	//{
	//	printf("插入成功\n");
	//	PrintList(L);
	//}else{
	//	printf("插入失败\n");
	//}
	//ret = ListDelete(L,1,del);
	//if (ret)
	//{
	//	printf("删除成功\n");
	//	printf("删除的元素：%d\n",del);
	//	PrintList(L);
	//}
	//else {

	//	printf("删除失败\n");
	//}
	//ret = LocateElem(L, 60);
	//if (ret)
	//{
	//	printf("按值查找成功\n");
	//	printf("该元素的位置：%d\n",ret);
	//}
	//else
	//{
	//	printf("查找失败，不存在此元素\n");
	//}



	SeqList DL;//dynamicList
	InitSeqList(DL);
	DL.data[0] = 1;
	DL.length++;
	DL.data[1] = 2;
	DL.length++;
	for (int i = 0; i < DL.length; i++)
	{
		printf("%3d", DL.data[i]);
	}
	return 0;
}