#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Step(int stepNum) {
	if (stepNum == 0)
		return 0;
	else if (stepNum == 1)
		return 1;
	else if (stepNum == 2)
		return 2;
	else
	{
		return Step(stepNum - 1) + Step(stepNum - 2);
	}
}

int main() {
	int stepNum;
	scanf("%d",&stepNum);
	int result;
	result = Step(stepNum);
	printf("%d",result);
	return 0;
}