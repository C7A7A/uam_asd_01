#ifndef STACK_H 
#define STACK_H 
#include <stdbool.h>
typedef
struct stack{
	int data[10];
	int top;
}
Stack;	

void stackInit(Stack *S);
void stackPush(Stack *S, int k);
void stackPop(Stack *S);
bool stackEmpty(Stack S);
void stackMerge(Stack *A, Stack *B, Stack *C);
void stackWrite(Stack S);
void stackEmptyWrite(Stack S);
#endif
