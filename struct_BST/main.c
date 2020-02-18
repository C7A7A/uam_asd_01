#include "treeBST.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	Tree T;
	Node *N = (Node *)malloc(sizeof(Node));
	
	treeInit(&T);
	treeInsert(&T, 15);
	treeInsert(&T, 5);
	treeInsert(&T, 16);
	treeInsert(&T, 3);
	treeInsert(&T, 12);
	treeInsert(&T, 20);
	treeInsert(&T, 10);
	treeInsert(&T, 6);
	treeInsert(&T, 7);
	treeInsert(&T, 13);
	treeInsert(&T, 18);
	treeInsert(&T, 23);
	treePrint(T);
	printf("%d\n", treeSearchRecursive(T, 13)->key);
	printf("%d\n", treeSearchIterative(T, 13)->key);
	N = treeSearchRecursive(T, 5);
	printf("%d\n", treeSuccessor(N)->key);
	N = treeSearchRecursive(T, 13);
	printf("%d\n", treeSuccessor(N)->key);
	treeDelete(&T, 13);
	treePrint(T);
	treeDelete(&T, 16);
	treePrint(T);
	treeDelete(&T, 5);
	treePrint(T);
	treeClear(&T);
	treePrint(T);
	
	printf("\nNastepnik najmniejszego:\n");
	treeInit(&T);
	treeInsert(&T, 15);
	treeInsert(&T, 5);
	treeInsert(&T, 16);
	treeInsert(&T, 3);
	treeInsert(&T, 12);
	treeInsert(&T, 20);
	treeInsert(&T, 10);
	treeInsert(&T, 6);
	treeInsert(&T, 7);
	treeInsert(&T, 13);
	treeInsert(&T, 18);
	treeInsert(&T, 23);
	printf("%d\n", treeSuccessorLowest(&T)->key);
	
	return 0;
}
