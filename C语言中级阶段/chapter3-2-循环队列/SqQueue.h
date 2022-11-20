#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];//存 MaxSize-1，个元素
	int front, rear;//队列头，队列尾
}SqQueue;

void InitQueue(SqQueue& Q) {
	Q.front = Q.rear = 0;
}

bool isEmpty(SqQueue Q) {
	if (Q.front == Q.rear)//判断栈空，不需要为0
		return true;
	else
		return false;
}

bool EnQueue(SqQueue& Q,ElemType e) {
	if ((Q.rear + 1) % MaxSize == Q.front)
		return false;//队满
	//Q.data[Q.rear++] = e;//这里不需进行 Q.rear++ ,否则下面（Q.rear+1）会多加一次
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MaxSize;
	return true;
}

bool DeQueue(SqQueue& Q, ElemType& e) {
	if (isEmpty(Q))
		return false;//栈空
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