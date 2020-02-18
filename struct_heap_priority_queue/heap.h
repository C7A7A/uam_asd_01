#ifndef HEAP_H
#define HEAP_H

typedef
struct heap{
	int data[20];
	int length;
	int heapSize;
}Heap;

void heapInit(Heap *T, int tab[], int tabLength);
void heapWrite(Heap T);

void buildMaxHeap(Heap *T);
void heapMaximum(Heap T);
void heapExtractMax(Heap *T);
void heapIncreaseKey(Heap *T, int node, int key);
void maxHeapInsert(Heap *T, int key);


/*--- ÆWICZENIA ---*/
void buildMinHeap(Heap *T);
void heapExtract(Heap *T, int node);
void heapMinimum(Heap *T);
void heapSort(Heap *T);
#endif
