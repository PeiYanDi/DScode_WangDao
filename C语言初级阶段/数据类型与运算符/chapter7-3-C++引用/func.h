#include <stdio.h>
//C++������  &д���βε�λ�ã���ʱ�Ĳ���=main�����еĲ���
void modifyNum(int& b) {
	++b;
}
//C���Ե�ָ�����ã������C++�Ƚ��鷳��
void modify_num(int* d) {
	++(*d);
}

void modifyPointer(int *&p) {
	//p 0x005efa54{10} ָ�����
	//&p ָ������ĵ�ַ 0x005efa60{0x005efa54{10}}
	//*p 10
	
	(*p)++;//*p=10
}