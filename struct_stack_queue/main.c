#include "stack.h"
#include "queue.h"
#include <stdio.h>

int main() {
	struct stack S;
	struct stack S1;
	struct stack S2;
	struct stack S3;
	
	int length;
	struct queue Q;
	struct queue Q1;
	struct queue Q2;
	struct queue Q3;
	
	stackInit(&S);
	stackPush(&S, 1);
	stackPush(&S, 2);
	stackWrite(S);
	stackPush(&S, 3);
	stackWrite(S);
	stackEmptyWrite(S);
	stackPop(&S);
	stackPop(&S);
	stackWrite(S);
	stackPop(&S);
	stackPop(&S);
	stackWrite(S);
	stackEmptyWrite(S);
	
	printf("\n");
	
	queueInit(&Q);
	enqueue(&Q, 1);
	enqueue(&Q, 2);
	queueWrite(Q);
	enqueue(&Q, 3);
	queueWrite(Q);
	queueEmptyWrite(Q);
	dequeue(&Q);
	dequeue(&Q);
	queueWrite(Q);
	dequeue(&Q);
	dequeue(&Q);
	queueWrite(Q);
	queueEmptyWrite(Q);
	
	printf("\nZADANIA 1-3\n");
	printf("\nS T O S\n");
	
	stackInit(&S1);
	stackInit(&S2);
	stackInit(&S3);
	
	stackPush(&S1, 10);
	stackPush(&S1, 20);
	stackPush(&S1, 30);
	stackPush(&S1, -1);
	stackPush(&S2, 100);
	stackPush(&S2, 200);
	stackPush(&S2, 200);
	stackPush(&S2, 200);
	stackPush(&S2, 200);
	stackPush(&S2, 200);
	stackWrite(S1);
	stackWrite(S2);
	stackMerge(&S1, &S2, &S3);
	stackWrite(S3);
	stackPop(&S3);
	stackPush(&S3, 123);
	stackWrite(S3);
	stackPush(&S3, 123);
	stackWrite(S3);
	
	printf("\nK O L E J K A\n");
	
	queueInit(&Q1);
	queueInit(&Q2);
	queueInit(&Q3);
	
	enqueue(&Q1, 12);
	enqueue(&Q1, 21);
	enqueue(&Q1, 3);
	enqueue(&Q2, 200);
	enqueue(&Q2, 100);
	enqueue(&Q2, 200);
	queueWrite(Q1);
	queueWrite(Q2);
	queueWrite(Q3);
	length = queueLength(&Q1);
	printf("%d\n", length);
	queueMerge(&Q1, &Q2, &Q3);
	queueWrite(Q3);
	return 0;
}
