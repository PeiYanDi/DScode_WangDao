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
	scanf("%d", delPostion);//δ�� &

	���ش���
		0x7987FC66 (ucrtbased.dll) (��ʱ10��ҵ.exe ��)����δ��������쳣: ��һ����Ч�������ݸ��˽���Ч������Ϊ���ش���ĺ�����

	ԭ��
		stream��Ч���ļ���ʧ�ܡ� ����·��ûд������û�и��ļ����ٻ����ļ���ռ�ã�
		�����������ص����ļ�û�б��򿪣�stream�ļ�������Ч�ġ�
		���㴫�˸���Ч����ȥ�����ļ������ڴ棬�ͻᱻ��Ϊ�����ش���
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