/*
����3 4 5 6 7 9999һ��������9999���������ͨ��β�巨�½��������ҵڶ���λ�õ�ֵ�������
��2��λ�ò���99�����Ϊ  3 99  4  5  6  7��ɾ����4��λ�õ�ֵ����ӡ���Ϊ  3 99  4  6  7��
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
		printf("%3d", L->data);//��ӡ��ǰ�������
		L = L->next;//ָ����һ�����
	}
	printf("\n");
}

void Create_List_Tail(LinkList& L) {
	LinkList s; ElemType e;
	L = (LinkNode*)malloc(sizeof(ElemType));
	L->next = NULL;
	LinkList r = L;//��rָ�����������һ��Ԫ��
	scanf("%d",&e);
	while (e!=9999)
	{
		s = (LinkNode*)malloc(sizeof(ElemType));
		s->data = e;
		s->next = r->next;
		r->next = s;
		r = s;//��rָ�����������һ��Ԫ��
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

//����Ų��ҽ��ֵ
LinkList GetElem(LinkList L, int pos) {
	LinkList p = L;//pָ��ͷ���
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
	p = GetElem(L, pos-1);//pָ�������λ�ý���ǰһ�����
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
	ElemType e;//�����������Ԫ�ص�ֵ
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