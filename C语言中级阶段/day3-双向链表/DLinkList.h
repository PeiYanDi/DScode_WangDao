#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct DNode {
	ElemType data;
	struct DNode* prior, * next;//前驱，后继
}DNode,*DLinkList;

DLinkList Dlist_head_insert(DLinkList& DL) {
	DNode* s;
	int x;
	DL = (DNode*)malloc(sizeof(DNode));
	DL->prior = NULL;
	DL->next = NULL;
	scanf("%d", &x);
	while (x != 9999) {
		s = (DNode*)malloc(sizeof(DNode));
		s->data = x;
		s->next = DL->next;
		if (DL->next != NULL) {//插入第一个结点时，不需要这一步操作
			DL->next->prior = s;
		}
		s->prior = DL;
		DL->next = s;
		scanf("%d", &x);
	}
	return DL;
}

DLinkList Dlist_tail_insert(DLinkList &DL) {
	//DLinkList s,r=DL;//此时DL还没有分配内存，r指向的空间不是后面DL申请的空间
	int x;
	DL = (DLinkList)malloc(sizeof(DNode));//先申请DL内存空间，在用DLinkList r = DL；
	DL->prior = NULL;
	DL->next = NULL;
	DLinkList s, r = DL;
	scanf("%d", &x);
	while (x != 9999) {
		s = (DLinkList)malloc(sizeof(DNode));
		s->data = x;
		r->next = s;
		s->prior = r;
		r = s;//r指向表尾结点
		scanf("%d",&x);
	}
	r->next = NULL;
	return DL;
}

void PrintDlist(DLinkList DL) {
	DLinkList p = DL->next;
	while (p != NULL) {
		printf("%3d", p->data);
		p = p->next;
	}
	printf("\n");
}
