#include "LinkQueue.h"

int main() {
	LinkQueue Q{};
	bool ret;
	ElemType out;//�洢����Ԫ��
	ret = isEmpty(Q);
	if (ret)
		printf("��ʽ����Ϊ��\n");
	else
		printf("��ʽ���в�Ϊ��\n");
	InitQueue(Q);
	EnQueue(Q, 1);
	EnQueue(Q, 2);
	EnQueue(Q, 3);
	DeQueue(Q, out);
	if (ret)
		printf("���ӳɹ�������Ԫ�أ�%d\n", out);
	else
		printf("����ʧ��\n");
	PrintLinkQueue(Q);
	return 0;
}