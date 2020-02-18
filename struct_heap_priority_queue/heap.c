#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

int parent(int key);
int left(int key);
int right(int key);
void maxHeapify(Heap *T, int node);
void minHeapify(Heap *T, int node);

void heapInit(Heap *T, int tab[], int tabLength){
	int i;
	T->length = tabLength;
	T->heapSize = sizeof(T->data)/sizeof(int);
	for(i = 0; i < tabLength; i++){
		T->data[i] = tab[i];
	}
}

int parent(int key){
	if(key == 0){
		return -1;
	}
	
	if(key%2 == 0){
		return (key/2 - 1);
	}else{
		return (key/2);
	}
}

int left(int key){
	if(key == 0){
		return 1;
	}else{
		return (key*2 + 1); 
	}
}

int right(int key){
	if(key == 0){
		return 2;
	}else{
		return (key*2 + 2);
	}
}

void buildMaxHeap(Heap *T){
	int i;
	for(i = (T->length/2 - 1); i >= 0; i--){
		maxHeapify(T, i);
	}
}

void maxHeapify(Heap *T, int node){
	int tmp;
	int toSwap = node;
	int leftNode = left(node);
	int rightNode = right(node);
	
	/*printf("LEFT: %d PARENT: %d RIGHT: %d\n", T->data[leftNode], T->data[node], T->data[rightNode]);*/
	if((T->data[leftNode] > T->data[toSwap]) && (leftNode < T->length)){
		toSwap = leftNode;
	}
	
	if((T->data[rightNode] > T->data[toSwap]) && (rightNode < T->length)){
		toSwap = rightNode;
	}
	
	if(toSwap != node){
		tmp = T->data[node];
		T->data[node] = T->data[toSwap];
		T->data[toSwap] = tmp;
		
		maxHeapify(T, toSwap);
	}
}

void maxHeapInsert(Heap *T, int key){
	int i;
	T->data[T->length] = key;
	T->length++;
	
	for(i = (T->length/2 - 1); i >= 0; i--){
		maxHeapify(T, i);
	}
}

void heapMaximum(Heap T){
	printf("%d\n", T.data[0]);
}

void heapExtractMax(Heap *T){
	int i;
	printf("%d\n", T->data[0]);
	T->data[0] = T->data[T->length - 1];
	T->length--;
	
	for(i = (T->length/2 - 1); i >= 0; i--){
		maxHeapify(T, i);
	}
}

void heapIncreaseKey(Heap *T, int node, int key){
	T->data[node - 1] = key;
	for(node = (T->length/2 - 1); node >= 0; node--){
		maxHeapify(T, node);
	}
}

void heapWrite(Heap T){
	int i;
	for(i = 0; i < T.length; i++){
		printf("%d ", T.data[i]);
	}
	printf("\n");
}

void buildMinHeap(Heap *T){
	int i;
	for(i = T->length/2 - 1; i >= 0; i--){
		minHeapify(T, i);
	}	
}

void minHeapify(Heap *T, int node){
	int tmp;
	int toSwap = node;
	int leftNode = left(node);
	int rightNode = right(node);
	
	if((T->data[leftNode] < T->data[toSwap]) && (leftNode < T->length)){
		toSwap = leftNode;
	}
	
	if((T->data[rightNode] < T->data[toSwap]) && (rightNode < T->length)){
		toSwap = rightNode;
	}
	
	if(toSwap != node){
		tmp = T->data[node];
		T->data[node] = T->data[toSwap];
		T->data[toSwap] = tmp;
		
		minHeapify(T, toSwap);
	}
}

void heapExtract(Heap *T, int node){
	int i;
	printf("%d\n", T->data[node]);
	T->data[node] = T->data[T->length - 1];
	T->length--;
	
	for(i = T->length/2 - 1; i >= 0; i--){
		minHeapify(T, i);
	}
}

void heapMinimum(Heap *T){
	int i;
	int minimum = T->data[T->length/2];
	for(i = T->length/2 + 1; i <= T->length - 1; i++){
		if(minimum > T->data[i]){
			minimum = T->data[i];
		}
	}
	printf("%d\n", minimum);
}

void heapSort(Heap *T){
	int i, tmp;
	for(i = T->length - 1; i >= 0; i--){
		tmp = T->data[0];
		T->data[0] = T->data[i];
		T->data[i] = tmp;
		maxHeapify(T, 0);
	}
}
