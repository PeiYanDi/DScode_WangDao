#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;

//顺序栈
typedef struct {
	ElemType data[MaxSize];
	int top;
}SqStack;

void InitStack(SqStack& S) {
	S.top = -1;//代表栈空
}

bool StackEmpty(SqStack& S) {
	if (S.top == -1) {
		return true;
	}
	else {
		return false;
	}
}

bool Push(SqStack& S,ElemType e) {
	if (S.top == MaxSize-1) {
		return false;
	}
	S.data[++S.top] = e;
	return true;
}

bool GetElem(SqStack& S,ElemType &e) {
	if (S.top == -1) {
		return false;
	}
	e = S.data[S.top];
	return true;
}

bool Pop(SqStack& S, ElemType &e) {
	if (S.top == -1) {
		return false;
	}
	e = S.data[S.top--];
	return true;
}

int main() {

	//实现栈，可以使用数组，也可以使用链表。这里使用的是数组
	SqStack S;
	bool flag;
	ElemType out;//存放拿出来的元素
	InitStack(S);
	flag = StackEmpty(S);
	if (flag) {
		printf("栈是空的\n");
	}
	Push(S, 1);
	Push(S, 2);
	Push(S, 3);
	flag = GetElem(S,out);//获得栈顶元素
	if (flag) {
		printf("栈顶元素成功取出：%d\n",out);
	}
	flag = Pop(S, out);
	if (flag) {
		printf("栈顶元素成功弹出：%d\n", out);
	}
	return 0;
}