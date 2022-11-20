#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct BSTNode {
	ElemType data;
	struct BSTNode* lchild, * rchild;
}BSTNode,*BiTree;
//54,20,66,40,28,79,58

bool BST_Insert(BiTree& T, ElemType e) {
	if (T == NULL) {
		T = (BiTree)malloc(sizeof(BSTNode));
		T->data = e;
		T->lchild = T->rchild = NULL;
		return true;
	}
	else if (e == T->data) {//������ͬԪ�أ��Ͳ�����
		return false;
	}
	else if (e < T->data) {//�ȸ����ֵС���������
		return BST_Insert(T->lchild, e);
	}
	else {//�ȸ��ڵ�ֵ�󣬷����ұ�
		return BST_Insert(T->rchild, e);
	}
}

void Creat_BST(BiTree& T, ElemType str[], int n) {
	T = NULL;
	int i = 0;
	while (i < n)
	{
		BST_Insert(T, str[i]);
		i++;
	}
}


void InOrder(BiTree T) {
	if (T != NULL) {
		InOrder(T->lchild);
		printf("%3d", T->data);
		InOrder(T->rchild);
	}
}
//�ǵݹ�ʵ�ֶ���������Ԫ�صĲ���
BiTree BST_Search(BiTree T, ElemType e, BiTree& p) {
	p = NULL;//parent <=> p ���ҽ��ֵ�ĸ��ڵ�
	while (T != NULL && e != T->data) {
		p = T;
		if (e < T->data)
			T = T->lchild;
		else
			T = T->rchild;
	}
	return T;
}
//�ݹ��㷨�򵥣���ִ��Ч�ʽϵ�
BiTree BSTRecursion_Search(BiTree T, ElemType e) {
	if (e == T->data) {
		return T;
	}
	else if (T == NULL) {
		return NULL;
	}
	else if (e < T->data) {
		return BSTRecursion_Search(T->lchild, e);
	}
	else {
		return BSTRecursion_Search(T->rchild, e);
	}
}

void Delete_BST_Node(BiTree&root,ElemType e) {
	if (root == NULL) {
		return;
	}
	if (root->data > e) {
		Delete_BST_Node(root->lchild, e);
	}
	else if (root->data < e) {
		Delete_BST_Node(root->rchild, e);
	}
	else//�ҵ���ɾ�����
	{
		if (root->lchild == NULL) {//���������Ϊ�գ�������������
			BiTree tempNode = root;
			root = root->rchild;
			free(tempNode);
		}
		else if (root->rchild == NULL) {//���������Ϊ�գ�������������
			BiTree tempNode = root->lchild;
			root = root->lchild;
			free(tempNode);
		}
		else {//�����������������
			//һ��ɾ�����ԣ���������������� or ����������С���ݣ�������Ҫɾ���Ľ��
			BiTree tempNode = root->lchild;
			if (tempNode->rchild != NULL) {
				tempNode = tempNode->rchild;
			}
			root->data = tempNode->data;
			Delete_BST_Node(root->lchild, tempNode->data);
		}
	}
}

int main() {
	BiTree T;
	BiTree parent;//�洢���׽��ĵ�ֵַ
	BiTree search;
	ElemType str[] = { 54,20,66,40,28,79,58 };
	Creat_BST(T, str,7);
	InOrder(T);
	printf("\n");

	search = BST_Search(T, 40, parent);//�ǵݹ����
	if (search)
	{
		printf("�ҵ���Ӧ��㣬ֵ=%d\n", search->data);
	}
	else {
		printf("δ�ҵ���Ӧ���\n");
	}

	search = BSTRecursion_Search(T, 79);//�ݹ����
	if (search)
	{
		printf("�ҵ���Ӧ��㣬ֵ=%d\n", search->data);
	}
	else {
		printf("δ�ҵ���Ӧ���\n");
	}

	Delete_BST_Node(T, 66);
	InOrder(T);
	printf("\n");
	return 0;
}