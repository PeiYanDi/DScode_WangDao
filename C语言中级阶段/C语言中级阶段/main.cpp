#include <stdio.h>
#include "SqList.h"
#include "SeqList.h"


int main() {
	//SqList L;
	//bool ret;//C����û��bool���͵�����--->����stdbool.hͷ�ļ�����;C++�д���bool����
	//ElemType del;//Ҫɾ��������
	////�ֶ�����SqList�и�ֵ
	//L.data[0] = 1;
	//L.data[1] = 2;
	//L.data[2] = 3;
	//L.length = 3;
	//ret = ListInsert(L, 2, 60);
	//if (ret)
	//{
	//	printf("����ɹ�\n");
	//	PrintList(L);
	//}else{
	//	printf("����ʧ��\n");
	//}
	//ret = ListDelete(L,1,del);
	//if (ret)
	//{
	//	printf("ɾ���ɹ�\n");
	//	printf("ɾ����Ԫ�أ�%d\n",del);
	//	PrintList(L);
	//}
	//else {

	//	printf("ɾ��ʧ��\n");
	//}
	//ret = LocateElem(L, 60);
	//if (ret)
	//{
	//	printf("��ֵ���ҳɹ�\n");
	//	printf("��Ԫ�ص�λ�ã�%d\n",ret);
	//}
	//else
	//{
	//	printf("����ʧ�ܣ������ڴ�Ԫ��\n");
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