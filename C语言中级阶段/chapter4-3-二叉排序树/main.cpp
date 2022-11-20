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
	else if (e == T->data) {//发现相同元素，就不插入
		return false;
	}
	else if (e < T->data) {//比根结点值小，放在左边
		return BST_Insert(T->lchild, e);
	}
	else {//比根节点值大，放在右边
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
//非递归实现二叉排序树元素的查找
BiTree BST_Search(BiTree T, ElemType e, BiTree& p) {
	p = NULL;//parent <=> p 查找结点值的父节点
	while (T != NULL && e != T->data) {
		p = T;
		if (e < T->data)
			T = T->lchild;
		else
			T = T->rchild;
	}
	return T;
}
//递归算法简单，但执行效率较低
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
	else//找到了删除结点
	{
		if (root->lchild == NULL) {//如果左子树为空，将右子树顶上
			BiTree tempNode = root;
			root = root->rchild;
			free(tempNode);
		}
		else if (root->rchild == NULL) {//如果右子树为空，将左子树顶上
			BiTree tempNode = root->lchild;
			root = root->lchild;
			free(tempNode);
		}
		else {//如果左右子树都存在
			//一般删除策略：左子树的最大数据 or 右子树的最小数据，来代替要删除的结点
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
	BiTree parent;//存储父亲结点的地址值
	BiTree search;
	ElemType str[] = { 54,20,66,40,28,79,58 };
	Creat_BST(T, str,7);
	InOrder(T);
	printf("\n");

	search = BST_Search(T, 40, parent);//非递归查找
	if (search)
	{
		printf("找到对应结点，值=%d\n", search->data);
	}
	else {
		printf("未找到对应结点\n");
	}

	search = BSTRecursion_Search(T, 79);//递归查找
	if (search)
	{
		printf("找到对应结点，值=%d\n", search->data);
	}
	else {
		printf("未找到对应结点\n");
	}

	Delete_BST_Node(T, 66);
	InOrder(T);
	printf("\n");
	return 0;
}