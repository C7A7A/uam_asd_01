#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>
typedef
struct queue{
	int data[10];
	int head;
	int tail;
} 
Queue;

void queueInit(Queue *Q);
bool queueEmpty(Queue Q);
void enqueue(Queue *Q, int k);
void dequeue(Queue *Q);
void queueMerge(Queue *A, Queue *B, Queue *C);
int queueLength(Queue *Q);
void queueWrite(Queue Q);
void queueEmptyWrite(Queue Q);
	
#endif
