#include "LinkList.h"

int main() {
	LinkList L;
	CreateListHead(L);
	PrintList(L);
	/*CreateListTail(L);
	PrintList(L);*/

	LinkList temp = GetElem(L, 1);
	printf("1��λ��Ԫ�ص�ֵΪ��%d\n", temp->data);
	int position = LocateElem(L, 4);
	printf("Ԫ��4��λ������Ϊ��%d\n", position);
	ElemType del = ListDelete(L,4);
	printf("���Ϊ4��Ԫ�ر�ɾ������ɾ��Ԫ��ֵΪ��%d\n", del);
	bool ret = ListInsert(L,3,5);
	if (ret) {
		PrintList(L);
	}else{
		printf("����ʧ��\n");
	}
	return 0;
}