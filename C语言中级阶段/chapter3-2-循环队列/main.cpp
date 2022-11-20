#include "SqQueue.h"
//循环队列

int main() {
	SqQueue Q;
	bool ret;//存储返回值
	ElemType out = 0;//存储出队的元素
	InitQueue(Q);
	ret = isEmpty(Q);
	if (ret)
		printf("对列为空\n");
	else
		printf("队列不为空\n");
	EnQueue(Q, 1);
	EnQueue(Q, 2);
	EnQueue(Q, 3);
	ret = EnQueue(Q, 4);
	if (ret)
		printf("入队成功\n");
	else
		printf("入队失败\n");
	ret = DeQueue(Q,out);
	if (ret)
		printf("出队成功，元素：%d\n", out);
	else
		printf("出队失败\n");
	ret = EnQueue(Q, 5);
	if (ret)
		printf("入队成功\n");
	else
		printf("入队失败\n");
	PrintSqQueue(Q);
	PrintSqQueue(Q);
	return 0;
}