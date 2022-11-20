/*
读取字符串abcdefghij，然后层次建树建立一颗二叉树，然后前序遍历输出abdhiejcfg
	两个问题：
		1.层次建树（字符）
		2.前序遍历
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef char BiElemType;
//二叉树
typedef struct BiTNode {
	BiElemType data;
	BiTNode* lchild, * rchild;
}BiTNode,*BiTree;

//以二叉树，作为链表中的元素
typedef struct BiTNode_LinkNode {
	BiTree biTNode_data;//树的某一个结点的地址值，也可以理解为，树中的一个小二叉树
	struct BiTNode_LinkNode* biTNode_next;
}BiTNode_LinkNode,*BiTNode_Link;
typedef BiTree ElemType;//将BiTreee封装成栈、队列中的一个元素

//栈--->（顺序栈）
#define MaxSize 50
typedef struct {
	ElemType data;
	int top;
}SeqStack;
void Init_SeqStack(SeqStack S);
bool Stack_Is_Empty(SeqStack S);
void Push(SeqStack& S, ElemType e);
void Pop(SeqStack& S);
ElemType Get_Stack_Top_ElemType(SeqStack S);

//队列（链式队列）
typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}LinkNode;
typedef struct LinkQueue {
	struct LinkNode* front, * rear;//注意！！！这里是LinkNode类型的
}LinkQueue;
void Init_LinkQueue(LinkQueue& Q);
bool LinkQueue_Is_Empty(LinkQueue Q);
void EnLinkQueue(LinkQueue& Q, ElemType e);
bool DeLinkQueue(LinkQueue& Q, ElemType& e);


void PreOrder(BiTree T) {
	BiTNode* p = T;
	if (p != NULL) {
		//puts(p->data);函数使用错误，puts();--->返回值int类型的
		/*int __cdecl puts(
        _In_z_ char const* _Buffer
        );*/
		putchar(p->data);
		PreOrder(p->lchild);
		PreOrder(p->rchild);
	}
}
void InOrder(BiTree T) {
	BiTree p = T;
	if (p != NULL) {
		InOrder(p->lchild);
		putchar(p->data);
		InOrder(p->rchild);
	}
}
void PostOrder(BiTree T) {
	BiTree p = T;
	if (p != NULL) {
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		putchar(p->data);
	}
}
void Init_LinkQueue(LinkQueue& Q) {
	LinkNode* head = (LinkNode*)malloc(sizeof(LinkNode));//链式队列的头结点
	head->next = NULL;
	Q.front = Q.rear = head;
}
bool LinkQueue_Is_Empty(LinkQueue Q) {
	if (Q.front == Q.rear) {
		return true;
	}
	else
	{
		return false;
	}
}
void EnLinkQueue(LinkQueue& Q, BiTree p) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = p;
	s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
}
bool DeLinkQueue(LinkQueue& Q, ElemType& e) {
	if (LinkQueue_Is_Empty(Q))
		return false;
	LinkNode* p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p) {//注意！！！重点理解，如果此时链式队列中除头结点外，就一个结点的话
					  //          如果直接free(p)，Q.rear会直接丢失，无法在判断栈空的条件
		Q.rear = Q.front;
	}
	free(p);
	return true;
}
//层序遍历（广度优先遍历）---> 用栈来进行实现，非递归算法
void LevelOrder(BiTree T) {
	LinkQueue Q;
	Init_LinkQueue(Q);
	ElemType p = T;
	EnLinkQueue(Q,T);
	while (!(LinkQueue_Is_Empty(Q))) {
		DeLinkQueue(Q,p);
		putchar(p->data);
		if (p->lchild != NULL) {//将该结点的左孩子入队
			EnLinkQueue(Q, p->lchild);
		}
		if(p->rchild != NULL)//将该结点的右孩子入队
		{
			EnLinkQueue(Q, p->rchild);
		}
	}
	printf("\n");
}


int main() {
	/*层次建树*/
	BiTree tree = NULL;//树根--->（该二叉树）
	char c;
	BiTree pnew;
	BiTNode_LinkNode* phead = NULL, *ptail = NULL, *pcur = NULL;//--->  BiTNode_Link可以看作 以二叉树为元素的链式队列
	BiTNode_Link biTree_Link_Temp_Node;//用来临时存放 BiTNode_Link 中二叉树结点类型的元素
	while (scanf("%c", &c) != EOF) {
		if (c == '\n'){
			break;
		}
		//创造 二叉树结点元素 的临时接受结点
		pnew =(BiTree)calloc(1, sizeof(BiTNode));//临时接收节点，用来存放传输每一个进来的数据
		pnew->data = c;
		//创造以 二叉树为元素的链表 的临时接收结点； 并且下两行代码看出：BiTNode_Link中没有头结点
		biTree_Link_Temp_Node = (BiTNode_LinkNode*)calloc(1, sizeof(BiTNode_LinkNode));
		biTree_Link_Temp_Node->biTNode_data = pnew;

		if (tree == NULL) {//如果一开始二叉树就为空 ---> 开始建树；二叉树结点元素 的临时接受结点--->就是根节点
			tree = pnew;
			phead = biTree_Link_Temp_Node;
			ptail = biTree_Link_Temp_Node;
			pcur = biTree_Link_Temp_Node;
			continue;
		}
		else//树不为空，将以 二叉树为元素的链表 的临时接收结点，插入BiTNode_Link中（尾插、头插法都可以）
		{
			//尾插法
			//二叉树类型新结点放入BiTNode_Link中
			ptail->biTNode_next = biTree_Link_Temp_Node;
			//ptail 指向队尾
			ptail = biTree_Link_Temp_Node;
		}
		//BiTNode_Link中，当前所指结点 pcur的二叉树结点元素的左孩子为空时，pnew赋给它的左孩子
		if (pcur->biTNode_data->lchild == NULL) {
			pcur->biTNode_data->lchild = pnew;
		}//右孩子为空时，将pnew赋给它的有孩子，同时pcur向下移动
		else if (pcur->biTNode_data->rchild == NULL) {
			pcur->biTNode_data->rchild = pnew;
			pcur = pcur->biTNode_next;
		}
	}
	//PreOrder(tree);
	InOrder(tree);
	printf("\n");
	PostOrder(tree);
	printf("\n");
	LevelOrder(tree);
	printf("\n");
	return 0;
}