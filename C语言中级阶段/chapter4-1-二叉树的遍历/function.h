#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//������
typedef char BiElemType;
typedef struct BiTNode {
	BiElemType data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode,*BiTree;

typedef struct tag {
	BiTree p;//����ĳһ�����ĵ�ֵַ
	struct tag* pnext;
}tag_t,*ptag_t;

//�ص㣡����
typedef BiTree ElemType;//ջ�����У��洢�����ݵ�Ԫ��BiTree

//ջ
#define MaxSize 50
typedef struct {
	ElemType data[MaxSize];
	int top;
}SqStack;
void InitStack(SqStack &S);
bool StackEmpty(SqStack S);
bool Push(SqStack& S, ElemType e);
bool Pop(SqStack& S, ElemType &e);
//������©
bool GetStackTop(SqStack S,ElemType &e);

//����
typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}LinkNode;
typedef struct LinkQueue {
	LinkNode* front, * rear;
}LinkQueue;
void InitQueue(LinkQueue& Q);
bool IsEmpty(LinkQueue Q);//����ķ���ֵ���ͣ�����ʹ��������趨
void EnQueue(LinkQueue& Q, ElemType e);
bool DeQueue(LinkQueue& Q, ElemType &e);

