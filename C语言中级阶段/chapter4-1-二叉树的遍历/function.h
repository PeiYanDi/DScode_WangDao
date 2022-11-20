#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//二叉树
typedef char BiElemType;
typedef struct BiTNode {
	BiElemType data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode,*BiTree;

typedef struct tag {
	BiTree p;//树的某一个结点的地址值
	struct tag* pnext;
}tag_t,*ptag_t;

//重点！！！
typedef BiTree ElemType;//栈、队列；存储的数据单元：BiTree

//栈
#define MaxSize 50
typedef struct {
	ElemType data[MaxSize];
	int top;
}SqStack;
void InitStack(SqStack &S);
bool StackEmpty(SqStack S);
bool Push(SqStack& S, ElemType e);
bool Pop(SqStack& S, ElemType &e);
//容易遗漏
bool GetStackTop(SqStack S,ElemType &e);

//队列
typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}LinkNode;
typedef struct LinkQueue {
	LinkNode* front, * rear;
}LinkQueue;
void InitQueue(LinkQueue& Q);
bool IsEmpty(LinkQueue Q);//具体的返回值类型，根据使用情况来设定
void EnQueue(LinkQueue& Q, ElemType e);
bool DeQueue(LinkQueue& Q, ElemType &e);

