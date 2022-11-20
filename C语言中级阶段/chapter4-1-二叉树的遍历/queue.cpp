#include "function.h"

void InitQueue(LinkQueue &Q) {
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));//头结点
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
	Q.rear = s;//Q.rear指针，向后移动
}

bool DeQueue(LinkQueue& Q, ElemType& e) {
	if (IsEmpty(Q))
		return false;
	LinkNode* p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)//【重点！】如果删除的是，最后一个元素--->将链式队列置空【注：这里是 == 】
		Q.rear = Q.front;
	//如果，不这样的话，Q.rear 就随着free(p) 地址发生了变化；在后续“入队、出队”操作会出错
	free(p);
	return true;
}