#include <stdio.h>
#define MaxSize 50
typedef int ElemType;
typedef struct SqList {
    ElemType data[MaxSize];
    ElemType length;
}SqList;

void swap(ElemType& e,ElemType& x) {
    ElemType temp = x;
    x = e;
    e = temp;
}

void fun(SqList& L) {
    int i = 0, j = L.length-1;
    while (i < j) {
        while (L.data[i] < 0)
            i++;
        while (L.data[j] >= 0)
            j--;
        if (i<j)
            swap(L.data[i], L.data[j]);
    }
}
int main() {
    SqList L;
    L.data[0] = -1;
    L.data[1] = -2;
    L.data[2] = -1;
    L.data[3] = -2;
    L.data[4] = -3;
    L.length = 5;
    fun(L);
    for (int i = 0; i < L.length; i++)
    {
        printf("%3d", L.data[i]);
    }
    return 0;
}