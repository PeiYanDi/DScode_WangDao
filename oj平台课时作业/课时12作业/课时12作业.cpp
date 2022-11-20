/*
输入3 4 5 6 7 9999一串整数，9999代表结束，通过尾插法新建链表，查找第二个位置的值并输出，
在2个位置插入99，输出为  3 99  4  5  6  7，删除第4个位置的值，打印输出为  3 99  4  6  7。
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}LinkNode,*LinkList;

void PrintList(LinkList L)
{
	L = L->next;
	while (L != NULL)
	{
		printf("%3d", L->data);//打印当前结点数据
		L = L->next;//指向下一个结点
	}
	printf("\n");
}

void Create_List_Tail(LinkList& L) {
	LinkList s; ElemType e;
	L = (LinkNode*)malloc(sizeof(ElemType));
	L->next = NULL;
	LinkList r = L;//让r指向链表中最后一个元素
	scanf("%d",&e);
	while (e!=9999)
	{
		s = (LinkNode*)malloc(sizeof(ElemType));
		s->data = e;
		s->next = r->next;
		r->next = s;
		r = s;//让r指向链表中最后一个元素
		scanf("%d", &e);
	}
	r->next = NULL;
}

bool IsEmpty(LinkList L) {
	if (L->next == NULL) {
		return false;
	}
	else
	{
		return true;
	}
}

//按序号查找结点值
LinkList GetElem(LinkList L, int pos) {
	LinkList p = L;//p指向头结点
	if (IsEmpty(L) && pos >= 1) {
		while (p != NULL && pos != 0) {
			p = p->next;
			pos--;
		}
		return p;
	}
}

void Insert_Postion(LinkList& L, int pos,ElemType e) {
	LinkList p,q;
	p = GetElem(L, pos-1);//p指向待插入位置结点的前一个结点
	if (IsEmpty(L)) {
		LinkList s = (LinkList)malloc(sizeof(ElemType));
		s->data = e;
		s->next = p->next;
		p->next = s;
	}
}

ElemType Delete_Postion(LinkList& L, int pos) {
	LinkList p,q;
	ElemType del;
	p = GetElem(L, pos - 1);
	q = p->next;
	del = q->data;
	p->next = q->next;
	//free(q);
	return del;
}

int main() {
	LinkList L,p;
	ElemType e;//用来输出查找元素的值
	Create_List_Tail(L);
	//PrintList(L);
	p = GetElem(L, 2);
	printf("%d\n",p->data);
	Insert_Postion(L,2,99);
	PrintList(L);
	e = Delete_Postion(L,4);
	//printf("%d\n", e);
	PrintList(L);
	return 0;
}