#define MaxSize 50
typedef int ElemType;

//静态分配
typedef struct {
	ElemType data[MaxSize];
	int length;//当前顺序表中有多少个元素
}SqList;

bool ListInsert(SqList& L, int i, ElemType e) {
	if (i<1 || i>L.length + 1)//判断要插入的位置是否合法
	{
		return false;
	}
	if (L.length >= MaxSize)
	{
		return false;
	}
	for (int j = L.length; j >= i; j--)
	{
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return true;
}

//打印函数
void PrintList(SqList L) {
	for (int i = 0; i < L.length; i++)
	{
		printf("%3d", L.data[i]);
	}
	printf("\n");
}

bool ListDelete(SqList& L, int i, ElemType& e) {//i表示要插入的位置（1，2，3.。。）
	if (i > L.length || i < 1)//L.length--->(1,2,3...)
	{
		return false;
	}
	e = L.data[i - 1];
	for (int j = i; j < L.length; j++)
	{
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return true;
}

int LocateElem(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)
		{
			return i + 1;
		}
	}
	return 0;
}

