#include "list.h"
#include <stdio.h>

int main(){
	List L;
	listInit(&L);
	listWrite(L);
	listInsert(&L, 1);
	listInsert(&L, 2);
	listWrite(L);
	listInsert(&L, 3);
	printf("%d\n", listSearch(L, 2));
	printf("%d\n", listSearch(L, 4));
	listInsertAfter(&L, 4, 2);
	listWrite(L);
	listDelete(&L, 2);
	listWrite(L);
	listDelete(&L, 5);
	listWrite(L);
	listInsertBefore(&L, 5, 3);
	listWrite(L);
	listClear(&L);
	listWrite(L);
	
	printf("\nZADANIA\n");
	listInsert(&L, 120);
	listInsert(&L, 130);
	listInsert(&L, 140);
	listInsert(&L, 150);
	listWrite(L);
	printf("%d\n", listElementsIteratively(L));
	printf("%d\n", listElementsRecursively(L.head));
	listReverse(&L);
	listWrite(L);
	return 0;
}
