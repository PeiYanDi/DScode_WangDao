#include <stdlib.h>
//��̬����
#define InitSize 100
typedef int ElemType;

typedef struct {
	ElemType* data;
	int capacity;//��̬������������
	int length;
}SeqList;

/*
	��ʼ��˳�����̬����洢�ռ�
	˳���L��������
*/
void InitSeqList(SeqList &L) {
	L.data = (ElemType*)malloc(sizeof(ElemType) * InitSize);
	//malloc()����������"stdlib.h"ͷ�ļ��еģ���Ҫ����ͷ�ļ�
	L.length = 0;
	L.capacity = InitSize;
}