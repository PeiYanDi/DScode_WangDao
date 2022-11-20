#include "function.h"

//�ݹ�ʵ��
void preOrder(BiTree p) {
	if (p!=NULL)
	{
		putchar(p->data);
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
}

void InOrder(BiTree p) {
	if (p!=NULL)
	{
		InOrder(p->lchild);
		putchar(p->data);
		InOrder(p->rchild);
	}
}

//��������ǵݹ�(Non-Recursion)
void InOrderNonRecursion(BiTree T) {
	SqStack S;
	InitStack(S);
	BiTree p = T;
	while (p || !StackEmpty(S)) {
		if (p) {
			Push(S, p);
			p = p->lchild;
		}
		else
		{
			Pop(S, p);
			putchar(p->data);
			p = p->rchild;
		}
	}
}

void PostOrder(BiTree p) {
	if (p!=NULL)
	{
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		putchar(p->data);
	}
}

//�������  ������ȱ���
void LevelOrder(BiTree T) {
	LinkQueue Q;
	InitQueue(Q);//���֮ǰ��Ҫ�ȳ�ʼ�����У�����Q.front Q.rear ��û���ڴ�ռ�ģ�����֡�д�����Ȩ�޳�ͻ��
	BiTree p;
	EnQueue(Q, T);
	while (!IsEmpty(Q)) {
		DeQueue(Q,p);//��ջ�д�ŵĽ�㣬�� BiTree p ������
		putchar(p->data);//��terminal��ʾ��α����Ľ��
		if (p->lchild != NULL)
			EnQueue(Q, p->lchild);
		if (p->rchild != NULL)
			EnQueue(Q, p->rchild);
	}
}

int main() {
	BiTree pnew;
	char c;
	BiTree tree = NULL;//����
	ptag_t phead = NULL, ptail = NULL, listpnew, pcur = NULL;
	//phead����ͷ��ptail����β
	
	/*EOF(end of file)�����ļ��Ľ�����ͨ�����ж��ļ��Ĳ����Ƿ�����ı�־��Ctrl+Zǿ��ֹͣ*/
	//abcdefghij
	while (scanf("%c", &c)!=EOF) {
		if (c=='\n')
		{
			break;
		}
		pnew = (BiTNode*)calloc(1,sizeof(BiTNode));//calloc����ռ䲢�Կռ���г�ʼ������ֵΪ0
		pnew->data = c;//������װ��ȥ
		listpnew = (ptag_t)calloc(1, sizeof(tag_t));//�����нڵ�����ռ�
		listpnew->p = pnew;//listpnew->p����ĳһ���ĵ�ֵַ��ָ����
		if (tree == NULL) {
			tree = pnew;//���ĸ�
			phead = listpnew;//����ͷ
			ptail = listpnew;//����β
			pcur = listpnew;//pcurrent
			continue;
		}
		else
		{
			ptail->pnext = listpnew;//�½���������ͨ��β�巨
			ptail = listpnew;//ptialָ�����β��
		}//pcur ʼ��ָ��Ҫ����Ľ���λ��
		if (pcur->p->lchild == NULL) {
			pcur->p->lchild = pnew;//���½����뵽Ҫ�Ӳ���������
		}
		else if (pcur->p->rchild==NULL)
		{
			pcur->p->rchild = pnew;//���½�����Ҫ��������ұ�
			pcur = pcur->pnext;//���Ҷ����˽���pcurָ����е���һ�����
		}
	}
	printf("\n-------ǰ�����--------\n");
	preOrder(tree);
	printf("\n-------�������--------\n");
	InOrder(tree);
	printf("\n-------�ǵݹ��������--------\n");
	InOrderNonRecursion(tree);
	printf("\n-------�������--------\n");
	PostOrder(tree);
	printf("\n");
	LevelOrder(tree);
	printf("\n");
	system("pause");
	return 0;
}