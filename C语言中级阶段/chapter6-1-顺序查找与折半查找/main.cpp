#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int ElemType;
typedef struct {
	ElemType* elem;//����ָ��
	int TableLen;
}Sequenct_Search_Table;

void ST_Init(Sequenct_Search_Table& ST, int len) {
	ST.TableLen = len + 1;//������һ��λ�ã�Ϊ�˴��ڱ�
	ST.elem = (ElemType*)malloc(sizeof(ElemType) * ST.TableLen);
	srand(time(NULL));//���������
	for (int i = 0; i < ST.TableLen; i++)//Ϊɶ�������λ��Ҳ��������ݣ�Ϊ�۰���ҷ���
	{
		ST.elem[i] = rand() % 100;
	}
}

void ST_Print(Sequenct_Search_Table ST) {
	for (int i = 0; i < ST.TableLen; i++)
	{
		printf("%3d", ST.elem[i]);
	}
	printf("\n");
}

int Search_Seq(Sequenct_Search_Table ST, ElemType key) {
	for (int i = 0; i < ST.TableLen; i++)
	{
		if (ST.elem[i] == key) {
			return i+1;//���ﷵ�ص�ֵ���Ǵ�1��ʼ�ģ����Կ���return 0;
		}
	}
	return 0;
}

void BubbleSort(Sequenct_Search_Table ST) {
	for (int i = 0; i < ST.TableLen - 1; i++)//�Ƚ��ˣ�ST.TableLen-1���֣�11-1=10��
	{
		for (int j = ST.TableLen - 1; j > 0; j--)
		{//�������ǰ�����Ƚ�
			if (ST.elem[j] < ST.elem[j-1]) {
				ElemType temp = ST.elem[j - 1];
				ST.elem[j - 1] = ST.elem[j];
				ST.elem[j] = temp;
			}
		}
	}
}

int BinarySearch(Sequenct_Search_Table ST, ElemType key) {
	int low = 0, high = ST.TableLen - 1, mid;
	while (low<=high)//low > high ����ѭ��������
	{
		mid = (low + high) / 2;
		if (key > ST.elem[mid])
			low = mid + 1;
		else if (key < ST.elem[mid])
			high = mid - 1;
		else
			//return mid;//���ﷵ�ص�ֵ���Ǵ�0��ʼ�ģ�������return 0;
			return mid + 1;
	}
	return 0;
}

int main() {
	Sequenct_Search_Table ST;
	ElemType key;
	int pos;//�洢��ѯԪ�ص�λ��
	ST_Init(ST,10);
	ST_Print(ST);
	printf("������Ҫ������keyֵ\n");
	scanf_s("%d",&key);
	pos = Search_Seq(ST, key);//˳�����
	if (pos) {
		printf("���ҳɹ���λ��Ϊ%d\n",pos);
	}
	else {
		printf("����ʧ��\n");
	}
	BubbleSort(ST);
	ST_Print(ST);
	printf("���ֲ��ң�������Ҫ������keyֵ:\n");
	scanf_s("%d", &key);
	//�������飬���ֲ��Ҳ�������
	pos = BinarySearch(ST,key);
	if (pos)
	{
		printf("���ֲ���,���ҳɹ�,λ��Ϊ %d\n", pos);
	}
	else {
		printf("���ֲ���,����ʧ��\n");
	}
	
	return 0;
}