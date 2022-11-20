/*
��ȡ�ַ���abcdefghij��Ȼ���ν�������һ�Ŷ�������Ȼ��ǰ��������abdhiejcfg
	�������⣺
		1.��ν������ַ���
		2.ǰ�����
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef char BiElemType;
//������
typedef struct BiTNode {
	BiElemType data;
	BiTNode* lchild, * rchild;
}BiTNode,*BiTree;

//�Զ���������Ϊ�����е�Ԫ��
typedef struct BiTNode_LinkNode {
	BiTree biTNode_data;//����ĳһ�����ĵ�ֵַ��Ҳ�������Ϊ�����е�һ��С������
	struct BiTNode_LinkNode* biTNode_next;
}BiTNode_LinkNode,*BiTNode_Link;
typedef BiTree ElemType;//��BiTreee��װ��ջ�������е�һ��Ԫ��

//ջ--->��˳��ջ��
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

//���У���ʽ���У�
typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}LinkNode;
typedef struct LinkQueue {
	struct LinkNode* front, * rear;//ע�⣡����������LinkNode���͵�
}LinkQueue;
void Init_LinkQueue(LinkQueue& Q);
bool LinkQueue_Is_Empty(LinkQueue Q);
void EnLinkQueue(LinkQueue& Q, ElemType e);
bool DeLinkQueue(LinkQueue& Q, ElemType& e);


void PreOrder(BiTree T) {
	BiTNode* p = T;
	if (p != NULL) {
		//puts(p->data);����ʹ�ô���puts();--->����ֵint���͵�
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
	LinkNode* head = (LinkNode*)malloc(sizeof(LinkNode));//��ʽ���е�ͷ���
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
	if (Q.rear == p) {//ע�⣡�����ص���⣬�����ʱ��ʽ�����г�ͷ����⣬��һ�����Ļ�
					  //          ���ֱ��free(p)��Q.rear��ֱ�Ӷ�ʧ���޷����ж�ջ�յ�����
		Q.rear = Q.front;
	}
	free(p);
	return true;
}
//���������������ȱ�����---> ��ջ������ʵ�֣��ǵݹ��㷨
void LevelOrder(BiTree T) {
	LinkQueue Q;
	Init_LinkQueue(Q);
	ElemType p = T;
	EnLinkQueue(Q,T);
	while (!(LinkQueue_Is_Empty(Q))) {
		DeLinkQueue(Q,p);
		putchar(p->data);
		if (p->lchild != NULL) {//���ý����������
			EnLinkQueue(Q, p->lchild);
		}
		if(p->rchild != NULL)//���ý����Һ������
		{
			EnLinkQueue(Q, p->rchild);
		}
	}
	printf("\n");
}


int main() {
	/*��ν���*/
	BiTree tree = NULL;//����--->���ö�������
	char c;
	BiTree pnew;
	BiTNode_LinkNode* phead = NULL, *ptail = NULL, *pcur = NULL;//--->  BiTNode_Link���Կ��� �Զ�����ΪԪ�ص���ʽ����
	BiTNode_Link biTree_Link_Temp_Node;//������ʱ��� BiTNode_Link �ж�����������͵�Ԫ��
	while (scanf("%c", &c) != EOF) {
		if (c == '\n'){
			break;
		}
		//���� ���������Ԫ�� ����ʱ���ܽ��
		pnew =(BiTree)calloc(1, sizeof(BiTNode));//��ʱ���սڵ㣬������Ŵ���ÿһ������������
		pnew->data = c;
		//������ ������ΪԪ�ص����� ����ʱ���ս�㣻 ���������д��뿴����BiTNode_Link��û��ͷ���
		biTree_Link_Temp_Node = (BiTNode_LinkNode*)calloc(1, sizeof(BiTNode_LinkNode));
		biTree_Link_Temp_Node->biTNode_data = pnew;

		if (tree == NULL) {//���һ��ʼ��������Ϊ�� ---> ��ʼ���������������Ԫ�� ����ʱ���ܽ��--->���Ǹ��ڵ�
			tree = pnew;
			phead = biTree_Link_Temp_Node;
			ptail = biTree_Link_Temp_Node;
			pcur = biTree_Link_Temp_Node;
			continue;
		}
		else//����Ϊ�գ����� ������ΪԪ�ص����� ����ʱ���ս�㣬����BiTNode_Link�У�β�塢ͷ�巨�����ԣ�
		{
			//β�巨
			//�����������½�����BiTNode_Link��
			ptail->biTNode_next = biTree_Link_Temp_Node;
			//ptail ָ���β
			ptail = biTree_Link_Temp_Node;
		}
		//BiTNode_Link�У���ǰ��ָ��� pcur�Ķ��������Ԫ�ص�����Ϊ��ʱ��pnew������������
		if (pcur->biTNode_data->lchild == NULL) {
			pcur->biTNode_data->lchild = pnew;
		}//�Һ���Ϊ��ʱ����pnew���������к��ӣ�ͬʱpcur�����ƶ�
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