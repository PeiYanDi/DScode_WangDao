#include "function.h"

//递归实现
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

//中序遍历非递归(Non-Recursion)
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

//层序遍历  广度优先遍历
void LevelOrder(BiTree T) {
	LinkQueue Q;
	InitQueue(Q);//入队之前，要先初始化队列；否则，Q.front Q.rear 是没有内存空间的，会出现“写入访问权限冲突”
	BiTree p;
	EnQueue(Q, T);
	while (!IsEmpty(Q)) {
		DeQueue(Q,p);//把栈中存放的结点，用 BiTree p 来接收
		putchar(p->data);//在terminal显示层次遍历的结果
		if (p->lchild != NULL)
			EnQueue(Q, p->lchild);
		if (p->rchild != NULL)
			EnQueue(Q, p->rchild);
	}
}

int main() {
	BiTree pnew;
	char c;
	BiTree tree = NULL;//树根
	ptag_t phead = NULL, ptail = NULL, listpnew, pcur = NULL;
	//phead队列头、ptail队列尾
	
	/*EOF(end of file)就是文件的结束，通常来判断文件的操作是否结束的标志。Ctrl+Z强制停止*/
	//abcdefghij
	while (scanf("%c", &c)!=EOF) {
		if (c=='\n')
		{
			break;
		}
		pnew = (BiTNode*)calloc(1,sizeof(BiTNode));//calloc申请空间并对空间进行初始化，赋值为0
		pnew->data = c;//把数据装进去
		listpnew = (ptag_t)calloc(1, sizeof(tag_t));//给队列节点申请空间
		listpnew->p = pnew;//listpnew->p树的某一结点的地址值，指向树
		if (tree == NULL) {
			tree = pnew;//树的根
			phead = listpnew;//队列头
			ptail = listpnew;//队列尾
			pcur = listpnew;//pcurrent
			continue;
		}
		else
		{
			ptail->pnext = listpnew;//新结点放入链表，通过尾插法
			ptail = listpnew;//ptial指向队列尾部
		}//pcur 始终指向要插入的结点的位置
		if (pcur->p->lchild == NULL) {
			pcur->p->lchild = pnew;//把新结点放入到要从插入结点的左边
		}
		else if (pcur->p->rchild==NULL)
		{
			pcur->p->rchild = pnew;//把新结点放入要插入结点的右边
			pcur = pcur->pnext;//左右都放了结点后，pcur指向队列的下一个结点
		}
	}
	printf("\n-------前序遍历--------\n");
	preOrder(tree);
	printf("\n-------中序遍历--------\n");
	InOrder(tree);
	printf("\n-------非递归中序遍历--------\n");
	InOrderNonRecursion(tree);
	printf("\n-------后序遍历--------\n");
	PostOrder(tree);
	printf("\n");
	LevelOrder(tree);
	printf("\n");
	system("pause");
	return 0;
}