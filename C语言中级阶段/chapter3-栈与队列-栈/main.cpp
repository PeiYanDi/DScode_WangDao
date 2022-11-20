#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;

//˳��ջ
typedef struct {
	ElemType data[MaxSize];
	int top;
}SqStack;

void InitStack(SqStack& S) {
	S.top = -1;//����ջ��
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

	//ʵ��ջ������ʹ�����飬Ҳ����ʹ����������ʹ�õ�������
	SqStack S;
	bool flag;
	ElemType out;//����ó�����Ԫ��
	InitStack(S);
	flag = StackEmpty(S);
	if (flag) {
		printf("ջ�ǿյ�\n");
	}
	Push(S, 1);
	Push(S, 2);
	Push(S, 3);
	flag = GetElem(S,out);//���ջ��Ԫ��
	if (flag) {
		printf("ջ��Ԫ�سɹ�ȡ����%d\n",out);
	}
	flag = Pop(S, out);
	if (flag) {
		printf("ջ��Ԫ�سɹ�������%d\n", out);
	}
	return 0;
}