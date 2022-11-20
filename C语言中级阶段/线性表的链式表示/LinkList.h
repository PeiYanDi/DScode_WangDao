#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

//头插法建立新链表
LinkList CreateListHead(LinkList& L) {//list_head_insert
	LNode* s; int x;
	L = (LNode*)malloc(sizeof(LNode));//带头结点的链表
	L->next = NULL;
	LinkList r = L->next;//让r指向第一个结点
	scanf("%d", &x);
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = r;
		L->next = s;
		r = s;//这一步，很重要！--->让r一直指向第一个结点
		scanf("%d", &x);
	}
	return L;
}

//尾插法建立链表
LinkList CreateListTail(LinkList& L) {
	//LNode* s,*r = L;
	int x;
	L = (LNode*)malloc(sizeof(LNode));
	LinkList s, r = L;
	//可不加L->next = NULL;
	scanf("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;//r指向新的结点
		scanf("%d", &x);
	}
	r->next = NULL;
	return L;
}

//按序号查找结点值
LinkList GetElem(LinkList L, int i) {
	int j = 1;
	LinkList p = L->next;
	if (i < 1) {
		return NULL;
	}
	while (p && j < i) {
		p = p->next;
		j++;
	}
	return p;
}

//按值查找--->返回，该元素值的位置坐标
int LocateElem(LinkList L, ElemType e) {
	int j = 1;
	LinkList p = L->next;
	while (p && p->data != e) {
		p = p->next;
		j++;
	}
	return j;
}

//按序号删除结点，并返回结点的元素值
ElemType ListDelete(LinkList& L, int i) {
	LinkList p = GetElem(L, i - 1);
	if (p == NULL) {
		return 0;
	}
	LinkList q = p->next;
	int del = q->data;
	p->next = q->next;
	free(q);
	return del;
}

//在序号i处插入元素e
bool ListInsert(LinkList& L, int i, ElemType e) {
	LinkList p = GetElem(L, i - 1);
	if (p == NULL) {
		return false;
	}
	LinkList q = p->next;
	LinkList s;
	s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = q;
	p->next = s;
	return true;
}

void PrintList(LinkList L) {
	LinkList p;
	p = L->next;
	while (p != NULL)
	{
		printf("%3d", p->data);
		p = p->next;//指针变量p，向后一直走
	}
	printf("\n");
}

