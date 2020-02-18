#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	Tree T;
	
	srand(time(NULL));
	
	treeInit(&T);
	treeMake(&T, 10);
	treePrint(T);
	treePreOrder(T);
	printf("\n");
	treeInOrder(T);
	printf("\n");
	treePostOrder(T);
	printf("\n");
	treeClear(&T);
	treePrint(T);

	return 0;
}
