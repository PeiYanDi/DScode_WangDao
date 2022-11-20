#include "function.h"

void InitQueue(LinkQueue &Q) {
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));//ͷ���
	Q.front->next = NULL;
}

bool IsEmpty(LinkQueue Q) {
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}

void EnQueue(LinkQueue& Q, ElemType e) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = e;s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;//Q.rearָ�룬����ƶ�
}

bool DeQueue(LinkQueue& Q, ElemType& e) {
	if (IsEmpty(Q))
		return false;
	LinkNode* p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)//���ص㣡�����ɾ�����ǣ����һ��Ԫ��--->����ʽ�����ÿա�ע�������� == ��
		Q.rear = Q.front;
	//������������Ļ���Q.rear ������free(p) ��ַ�����˱仯���ں�������ӡ����ӡ����������
	free(p);
	return true;
}