/*输入3 4 5 6 7 9999一串整数，9999代表结束，通过头插法新建链表，并输出，通过尾插法新建链表并输出。*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LinkNode{
	ElemType data;
	struct LinkNode* next;
}LinkNode,*LinkList;


void PrintList(LinkList L){
	L = L->next;
	while (L != NULL)
	{
		printf("%d", L->data);//打印当前结点数据
		L = L->next;//指向下一个结点
		if (L != NULL)
		{
			printf(" ");
		}	
	}
	printf("\n");
}

void InitLinkList(LinkList& L) {
	L = (LinkList)malloc(sizeof(ElemType));
	L->next = NULL;
}

void Insert_Tail(LinkList& L) {
	ElemType e;
	LinkList s, r = L;
	scanf("%d", &e);
	while ( e != 9999)
	{
		s = (LinkList)malloc(sizeof(ElemType));
		s->data = e;
		r->next = s;
		r = s;//r向后移动
		scanf("%d", &e);
	}
	r->next = NULL;
}

void Insert_Head(LinkList& L) {
	ElemType e;
	LinkList s, r = L->next;
	scanf("%d", &e);
	while (e != 9999)
	{
		s = (LinkList)malloc(sizeof(ElemType));
		s->data = e;
		s->next = r;
		L->next = s;
		r = s;
		scanf("%d", &e);
	}
}

int main() {
	LinkList L;
	InitLinkList(L);
	ElemType e;
	Insert_Head(L);
	PrintList(L);
	Insert_Tail(L);
	PrintList(L);
	return 0;
}