#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

//ͷ�巨����������
LinkList CreateListHead(LinkList& L) {//list_head_insert
	LNode* s; int x;
	L = (LNode*)malloc(sizeof(LNode));//��ͷ��������
	L->next = NULL;
	LinkList r = L->next;//��rָ���һ�����
	scanf("%d", &x);
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = r;
		L->next = s;
		r = s;//��һ��������Ҫ��--->��rһֱָ���һ�����
		scanf("%d", &x);
	}
	return L;
}

//β�巨��������
LinkList CreateListTail(LinkList& L) {
	//LNode* s,*r = L;
	int x;
	L = (LNode*)malloc(sizeof(LNode));
	LinkList s, r = L;
	//�ɲ���L->next = NULL;
	scanf("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;//rָ���µĽ��
		scanf("%d", &x);
	}
	r->next = NULL;
	return L;
}

//����Ų��ҽ��ֵ
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

//��ֵ����--->���أ���Ԫ��ֵ��λ������
int LocateElem(LinkList L, ElemType e) {
	int j = 1;
	LinkList p = L->next;
	while (p && p->data != e) {
		p = p->next;
		j++;
	}
	return j;
}

//�����ɾ����㣬�����ؽ���Ԫ��ֵ
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

//�����i������Ԫ��e
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
		p = p->next;//ָ�����p�����һֱ��
	}
	printf("\n");
}

