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
	return h % MaxKey;//������±꣬Ҫ����MaxKeyȡ�ࣨҲ����ȡģ��
}

int main() {
	const char* pStr[5] = { "xiongda","lele","hanmeimei","wangdao","fenghua" };
	int i;
	int* p;
	
	const char* pHash_Table[MaxKey] = { NULL };//pHash_Table����ϣ��ɢ�б�
	for ( i = 0; i < 5; i++)
	{
		p = &i;
		printf("%s is key = %d\n", pStr[i], hash(pStr[i]));
		pHash_Table[hash(pStr[i])] = pStr[i];
	}
}