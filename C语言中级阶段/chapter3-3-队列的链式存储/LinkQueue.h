#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LinkNode{
	ElemType data;
	struct LinkNode* next;
}LinkNode;
typedef struct {
	LinkNode* front, * rear;//����ͷ������β
}LinkQueue;

void InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));//ͷ���
	//ͷ��βָ��ͬһ�����
	Q.front->next = NULL;
}

bool isEmpty(LinkQueue Q) {
	if (Q.front = Q.rear)
		return true;
	else
		return false;
}

bool EnQueue(LinkQueue& Q, ElemType e) {
	if (Q.front = Q.rear)
		return false;
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = e;
	s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
	return true;
}

bool DeQueue(LinkQueue& Q, ElemType &e) {
	if (isEmpty(Q))
		return false;
	LinkNode* p=Q.front->next;//ͷ�����ǣ���һ�����
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)//ɾ���������һ��Ԫ��
		Q.rear = Q.front;//������Ϊ��
	free(p);
	return true;
}

void PrintLinkQueue(LinkQueue& Q) {
	for (Q.front; Q.front < Q.rear; Q.front++)
	{
		printf("%3d", Q.front->data);
	}
	printf("\n");
}