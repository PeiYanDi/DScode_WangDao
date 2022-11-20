/*
�½�һ��ջ����ȡ��׼����3������3 4 5����ջ3 4 5�����γ�ջ����ӡ 5 4 3��
�½�ѭ�����У�MaxsizeΪ5������ȡ��׼����3 4 5 6 7�����7ʱ����������ӡfalse��
Ȼ�����γ��ӣ���� 3 4 5 6
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
//ѭ������
typedef struct SeqQueue {
	ElemType data[Maxsize];
	int front,  rear;//����ͷ������β
}SeqQueue;
//��ʼ��ջ
void Init_Stack(Stack& S) {
	S.top = -1;
}

//ջ�Ƿ�Ϊ��
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
	��ôʵ�֣�ջ���������׼�����������? --->  ��û�н��

	�����������--->�ַ�������'\0'��Ϊ�ж���������Pushʱ���ڽ��ַ���ת��Ϊ����	
*/
void Push(Stack& S, ElemType e) {
	if (S.top == MaxSize - 1) {//�ж��Ƿ�ջ��
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
		return false;//����
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
		#define EOF -1 ---> C++���Զ���EOF=-1��

		int x,y,z;
		x = scanf("%d %d",&y,&z);
		scanf()�ķ���ֵ�ǳɹ���ֵ�ı������������淵�ص� x = 2;
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