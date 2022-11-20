#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];//�� MaxSize-1����Ԫ��
	int front, rear;//����ͷ������β
}SqQueue;

void InitQueue(SqQueue& Q) {
	Q.front = Q.rear = 0;
}

bool isEmpty(SqQueue Q) {
	if (Q.front == Q.rear)//�ж�ջ�գ�����ҪΪ0
		return true;
	else
		return false;
}

bool EnQueue(SqQueue& Q,ElemType e) {
	if ((Q.rear + 1) % MaxSize == Q.front)
		return false;//����
	//Q.data[Q.rear++] = e;//���ﲻ����� Q.rear++ ,�������棨Q.rear+1������һ��
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MaxSize;
	return true;
}

bool DeQueue(SqQueue& Q, ElemType& e) {
	if (isEmpty(Q))
		return false;//ջ��
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	return true;
}
void PrintSqQueue(SqQueue Q) {
	for ( Q.front; Q.front < Q.rear; Q.front++)
	{
		printf("%3d", Q.data[Q.front]);
	}
	printf("\n");
}