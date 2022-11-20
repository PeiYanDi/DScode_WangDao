#include "DLinkList.h"

int main() {
	DLinkList DL;
	//DL = Dlist_head_insert(DL);
	DL = Dlist_tail_insert(DL);
	PrintDlist(DL);
	return 0;
}