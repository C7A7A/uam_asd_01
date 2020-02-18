#include <stdio.h>
#include <stdbool.h>
#include "stack.h"
void stackInit(Stack *S){
	S->top = 0;
}

void stackPush(Stack *S, int k){
	if(S->top < sizeof(S->data)/sizeof(S->data[0])){
		S->data[S->top] = k;
		S->top++;
	}else{
		printf("przepelnienie stosu\n");
	}
}

void stackPop(Stack *S){
	if(S->top != 0){
		S->top--;
		printf("%d\n", S->data[S->top]);
		S->data[S->top] = 0;
	}else{
		printf("niedomiar\n");
	}
}

bool stackEmpty(Stack S){
		if(S.top == 0){
			return true;
		} return false;
}

void stackMerge(Stack *A, Stack *B, Stack *C){
	int i;
	int len = A->top + B->top;
	if(len < 11){
		for(i = 0; i < A->top; i++){
			stackPush(C, A->data[i]);
		}
		for(i = 0; i < B->top; i++){
			stackPush(C, B->data[i]);
		}
	}else{
		printf("dlugosc stosu nie moze przekraczac: %d\n", 10);
	}
}

void stackWrite(Stack S){
	int i;
	for(i = 0; i < S.top; i++){
		printf("%d ", S.data[i]);
	}
	printf("\n");
}

void stackEmptyWrite(Stack S){
	if(stackEmpty(S)){
		printf("true\n");
	}else{
		printf("false\n");
	}
}
