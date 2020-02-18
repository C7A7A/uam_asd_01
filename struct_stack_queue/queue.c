#include "queue.h"
#include <stdbool.h>

void queueInit(Queue *Q){
	Q->head = 0;
	Q->tail = 0;
}

bool queueEmpty(Queue Q){
	if(Q.head == Q.tail){
		return true;
	} return false;
}

void enqueue(Queue *Q, int k){
	if(Q->tail < 10){
		Q->data[Q->tail] = k;
		Q->tail++;
	}else{
		printf("przepelnienie\n");
	}
}

void dequeue(Queue *Q){
	if(Q->tail != Q->head){
		int i;
		printf("%d\n", Q->data[Q->head]);
		for(i = 0; i < Q->tail; i++){
			Q->data[i] = Q->data[i+1];
		}
		Q->tail--;
	}else{
		printf("niedomiar\n");
	}
}

void queueMerge(Queue *A, Queue *B, Queue *C){
	int i;
	int len = A->tail + B->tail;
	if(len < 11){
		for(i = 0; i < A->tail; i++){
			enqueue(C, A->data[i]);
		}
		for(i = 0; i < B->tail; i++){
			enqueue(C, B->data[i]);
		}
	}else{
		printf("dlugosc kolejki nie moze przekraczac: %d\n", 10);
	}
}

int queueLength(Queue *Q){
	return (Q->tail);
}

void queueWrite(Queue Q){
	int i;
	for(i = 0; i < Q.tail; i++){
		printf("%d ", Q.data[i]);
	}
	printf("\n");
}

void queueEmptyWrite(Queue Q){
	if(queueEmpty(Q)){
		printf("true\n");
	}else{
		printf("false\n");
	}
}
