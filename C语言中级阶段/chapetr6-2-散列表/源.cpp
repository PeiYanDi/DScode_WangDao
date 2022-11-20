#define MaxKey 1000
#include <stdio.h>
int hash(const char* key) {
	int h = 0, g;
	while (*key) {
		h = (h << 4) + *key++;
		g = h & 0xf0000000;
		if (g)
		{
			h ^= g >> 24;
		}
		h &= ~g;
	}
	return h % MaxKey;//算出的下标，要进行MaxKey取余（也就是取模）
}

int main() {
	const char* pStr[5] = { "xiongda","lele","hanmeimei","wangdao","fenghua" };
	int i;
	int* p;
	
	const char* pHash_Table[MaxKey] = { NULL };//pHash_Table：哈希表、散列表
	for ( i = 0; i < 5; i++)
	{
		p = &i;
		printf("%s is key = %d\n", pStr[i], hash(pStr[i]));
		pHash_Table[hash(pStr[i])] = pStr[i];
	}
}