#include "LinkQueue.h"

int main() {
	LinkQueue Q{};
	bool ret;
	ElemType out;//存储出队元素
	ret = isEmpty(Q);
	if (ret)
		printf("链式队列为空\n");
	else
		printf("链式队列不为空\n");
	InitQueue(Q);
	EnQueue(Q, 1);
	EnQueue(Q, 2);
	EnQueue(Q, 3);
	DeQueue(Q, out);
	if (ret)
		printf("出队成功，出队元素：%d\n", out);
	else
		printf("出队失败\n");
	PrintLinkQueue(Q);
	return 0;
}