#include "SqQueue.h"
//ѭ������

int main() {
	SqQueue Q;
	bool ret;//�洢����ֵ
	ElemType out = 0;//�洢���ӵ�Ԫ��
	InitQueue(Q);
	ret = isEmpty(Q);
	if (ret)
		printf("����Ϊ��\n");
	else
		printf("���в�Ϊ��\n");
	EnQueue(Q, 1);
	EnQueue(Q, 2);
	EnQueue(Q, 3);
	ret = EnQueue(Q, 4);
	if (ret)
		printf("��ӳɹ�\n");
	else
		printf("���ʧ��\n");
	ret = DeQueue(Q,out);
	if (ret)
		printf("���ӳɹ���Ԫ�أ�%d\n", out);
	else
		printf("����ʧ��\n");
	ret = EnQueue(Q, 5);
	if (ret)
		printf("��ӳɹ�\n");
	else
		printf("���ʧ��\n");
	PrintSqQueue(Q);
	PrintSqQueue(Q);
	return 0;
}