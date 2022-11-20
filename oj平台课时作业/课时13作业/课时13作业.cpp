/*
新建一个栈，读取标准输入3个整数3 4 5，入栈3 4 5，依次出栈，打印 5 4 3，
新建循环队列（Maxsize为5），读取标准输入3 4 5 6 7，入队7时，队满，打印false，
然后依次出队，输出 3 4 5 6
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MaxSize 20
#define Maxsize 5
typedef int ElemType;
typedef struct Stack {
	ElemType data[MaxSize];
	int top;
};
//循环队列
typedef struct SeqQueue {
	ElemType data[Maxsize];
	int front,  rear;//队列头、队列尾
}SeqQueue;
//初始化栈
void Init_Stack(Stack& S) {
	S.top = -1;
}

//栈是否为空
bool Is_Empty_Stack(Stack S) {
	if (S.top == -1) {
		return true;
	}
	else
	{
		return false;
	}
}
/*
	怎么实现，栈连续读入标准输入的数字呢? --->  还没有解决

	将输入的数字--->字符串，用'\0'作为判断条件，在Push时，在将字符串转变为数字	
*/
void Push(Stack& S, ElemType e) {
	if (S.top == MaxSize - 1) {//判断是否栈满
		return;
	}
	S.data[++S.top] = e;
}

void Pop(Stack& S) {
	while (!(Is_Empty_Stack(S))) {
		printf("%2d",S.data[S.top--]);
	}
	printf("\n");
}

void Init_SeqQueue(SeqQueue& Q) {
	Q.front = Q.rear = 0;
}

bool IsEmpty(SeqQueue Q) {
	if (Q.front == Q.rear) {
		return true;
	}
	else
	{
		return false;
	}
}

bool EnQueue(SeqQueue& Q, ElemType e) {
	if ((Q.rear + 1) % Maxsize == Q.front) {
		return false;//队满
	}
	Q.data[Q.rear++] = e;
	Q.rear=Q.rear%MaxSize;
	return true;
}

void DeQueue(SeqQueue Q) {
	while (!(IsEmpty(Q)))
	{
		printf("%2d",Q.data[Q.front++]);
		Q.front = Q.front % MaxSize;
	}
}

int main() {
	Stack S;
	Init_Stack(S);
	ElemType e;
	char c{};
	/*
		#define EOF -1 ---> C++语言定义EOF=-1；

		int x,y,z;
		x = scanf("%d %d",&y,&z);
		scanf()的返回值是成功赋值的变量数量，上面返回的 x = 2;
	*/
	for (int i = 0; i < 3; i++)
	{
		scanf("%d",&e);
		Push(S, e);
	}
	Pop(S);
	SeqQueue Q;
	Init_SeqQueue(Q);
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &e);
		if (EnQueue(Q, e)) {
			continue;
		}
		else
		{
			printf("false\n");
		}
	}
	DeQueue(Q);
	return 0;
}