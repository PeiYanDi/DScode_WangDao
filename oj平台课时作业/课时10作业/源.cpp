#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MaxSize 50
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];
	int Length;
}SeqList;

void Init(SeqList& Seq) {
	Seq.Length = 0;
}

void Insert(SeqList& Seq,int pos,ElemType e) {
	if (Seq.Length == 0 || pos > Seq.Length)
		return;
	for (int i = Seq.Length; i >= pos; i--)
	{
		Seq.data[i] = Seq.data[i - 1];
	}
	Seq.Length++;
	Seq.data[pos - 1] = e;
}

void Print(SeqList Seq) {
	for (int i = 0; i < Seq.Length; i++)
	{
		printf("%3d",Seq.data[i]);
	}
	printf("\n");
}

bool Delete(SeqList& Seq, int delPos) {
	if (delPos<1 || delPos>Seq.Length) {
		return false;
	}
	for (int i = delPos; i < Seq.Length; i++)
	{
		Seq.data[i - 1] = Seq.data[i];
	}
	Seq.Length--;
	return true;
}

int main() {
	SeqList Seq;
	Init(Seq);
	Seq.data[0] = 1;
	Seq.data[1] = 2;
	Seq.data[2] = 3;
	Seq.Length = 3;
	ElemType e=0;
	int delPostion=0;
	bool flag;

	scanf("%d", &e);
	Insert(Seq, 2,e);
	Print(Seq);
	scanf("%d", &delPostion);
	/*
	scanf("%d", delPostion);//未加 &

	严重错误：
		0x7987FC66 (ucrtbased.dll) (课时10作业.exe 中)处有未经处理的异常: 将一个无效参数传递给了将无效参数视为严重错误的函数。

	原因：
		stream无效，文件打开失败。 可能路径没写？可能没有该文件？再或者文件被占用？
		可能其它因素导致文件没有被打开，stream文件流是无效的。
		当你传了个无效参数去访问文件或者内存，就会被视为有严重错误
	*/
	flag = Delete(Seq, delPostion);
	if (flag) {
		Print(Seq);
	}
	else
	{
		printf("false");
	}
	return 0;
}