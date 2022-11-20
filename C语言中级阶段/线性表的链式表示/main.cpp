#include "LinkList.h"

int main() {
	LinkList L;
	CreateListHead(L);
	PrintList(L);
	/*CreateListTail(L);
	PrintList(L);*/

	LinkList temp = GetElem(L, 1);
	printf("1号位置元素的值为：%d\n", temp->data);
	int position = LocateElem(L, 4);
	printf("元素4的位置坐标为：%d\n", position);
	ElemType del = ListDelete(L,4);
	printf("序号为4的元素被删除，被删除元素值为：%d\n", del);
	bool ret = ListInsert(L,3,5);
	if (ret) {
		PrintList(L);
	}else{
		printf("插入失败\n");
	}
	return 0;
}