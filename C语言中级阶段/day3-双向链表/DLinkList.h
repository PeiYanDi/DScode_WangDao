#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct DNode {
	ElemType data;
	struct DNode* prior, * next;//ǰ�������
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
		if (DL->next != NULL) {//�����һ�����ʱ������Ҫ��һ������
			DL->next->prior = s;
		}
		s->prior = DL;
		DL->next = s;
		scanf("%d", &x);
	}
	return DL;
}

DLinkList Dlist_tail_insert(DLinkList &DL) {
	//DLinkList s,r=DL;//��ʱDL��û�з����ڴ棬rָ��Ŀռ䲻�Ǻ���DL����Ŀռ�
	int x;
	DL = (DLinkList)malloc(sizeof(DNode));//������DL�ڴ�ռ䣬����DLinkList r = DL��
	DL->prior = NULL;
	DL->next = NULL;
	DLinkList s, r = DL;
	scanf("%d", &x);
	while (x != 9999) {
		s = (DLinkList)malloc(sizeof(DNode));
		s->data = x;
		r->next = s;
		s->prior = r;
		r = s;//rָ���β���
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
