#include "heap.h"
#include <stdio.h>

int main() {
	Heap T;
	int tab[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
	heapInit(&T, tab, sizeof(tab)/sizeof(int));
	buildMaxHeap(&T);
	heapWrite(T);
	maxHeapInsert(&T, 15);
	heapWrite(T);
	heapMaximum(T);
	heapWrite(T);
	heapExtractMax(&T);
	heapWrite(T);
	heapIncreaseKey(&T, 4, 19);
	heapWrite(T);
	
	
	/*--- ÆWICZENIA ---*/
	printf("\n--- CWICZENIA ---\n");
	buildMinHeap(&T);
	heapWrite(T);
	heapExtract(&T, 0);
	heapWrite(T);
	heapExtract(&T, 5);
	heapWrite(T);
	
	buildMaxHeap(&T);
	heapWrite(T);
	heapMinimum(&T);
	heapSort(&T);
	heapWrite(T);
	return 0;
}
