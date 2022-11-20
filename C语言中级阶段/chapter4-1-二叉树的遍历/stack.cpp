#include "function.h"

void InitStack(SqStack& S) {
	S.top = -1;
}

bool StackEmpty(SqStack S) {
	if (S.top == -1) 
		return true;
	else
		return false;
}

bool Push(SqStack& S, ElemType e) {
	if (S.top == MaxSize - 1) {
		return false;
	}
	S.data[++S.top] = e;
	return true;
}

bool Pop(SqStack& S, ElemType& e) {
	if (StackEmpty(S)) {
		return false;
	}
	e = S.data[S.top--];
	return true;
}

bool GetStackTop(SqStack S, ElemType& e) {
	if (StackEmpty(S)) {
		return false;
	}
	e = S.data[S.top];
	return true;
}
