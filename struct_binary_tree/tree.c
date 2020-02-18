#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Node *treeRandomWalk(Node *N);
void treeNodePrint(Node *N, int depth);
void treeClearNodes(Node *N);
void treeWalk(Node *N, int depth);
void treePreOrderExec(Node *N);
void treeInOrderExec(Node *N);
void treePostOrderExec(Node *N);

void treeInit(Tree *T){
	T->root = NULL;
}

void treeMake(Tree *T, int k){
	int i, l;
	Node *x = (Node *)malloc(sizeof(Node));

	if(T->root == NULL){
		x->key = (1 + rand() % 100);
		x->p = NULL;
		x->left = NULL;
		x->right = NULL;
		T->root = x;
		/*printf("T->root->key: %d\n", T->root->key);*/
	}
	
	for(i = 0; i < k; i++){
		Node *n = (Node *)malloc(sizeof(Node));
		x = treeRandomWalk(T->root);
	
		n->p = x;
		n->key = (1 + rand() % 100);
		/*
		printf("n->key: %d\n", n->key);
		printf("n->p: %d\n", n->p->key);
		*/
		if(x->right == NULL && x->left == NULL){
			l = rand()%2;
			/*printf("L2: %d\n\n", l);*/
			if(l == 1){
				x->left = n;
			}else{
				x->right = n;
			}
		}else if(x->right == NULL){
			x->right = n;
			/*printf("x->right->key: %d\n\n", x->right->key);*/
		}else if(x->left == NULL){
			x->left = n;
			/*printf("x->left->key: %d\n\n", x->left->key);*/
		}
		
		n->left = NULL;
		n->right = NULL;
	}
}

Node *treeRandomWalk(Node *N){
	Node *x = N;
	Node *y = (Node *)malloc(sizeof(Node));
	int l;
	
	while(x != NULL){
		y = x;
		l = (rand()%2);
		/*
		printf("X->key: %d\n", x->key);
		printf("L: %d\n", l);
		*/
		if(l == 1){
			x = x->left;
		}else{
			x = x->right;
		}
	}
	return y;
}

void treePrint(Tree T){
	treeWalk(T.root, 0);
}

void treeWalk(Node *N, int depth){
	if(N != NULL){
		depth++;
		treeWalk(N->right, depth);
		
		treeNodePrint(N, depth);
		
		treeWalk(N->left, depth);	
	}
}

void treeNodePrint(Node *N, int depth){
	int i;
	for(i = 1; i < depth; i++){
		printf("\t");
	}
	printf("%d\n", N->key);
} 

void treePreOrder(Tree T){
	treePreOrderExec(T.root);
}

void treePreOrderExec(Node *N){
	if(N != NULL){
		printf("%d ", N->key);
		treePreOrderExec(N->left);
		treePreOrderExec(N->right);
	}
}

void treeInOrder(Tree T){
	treeInOrderExec(T.root);
}

void treeInOrderExec(Node *N){
	if(N != NULL){
		treeInOrderExec(N->left);
		printf("%d ", N->key);
		treeInOrderExec(N->right);
	}
}

void treePostOrder(Tree T){
	treePostOrderExec(T.root);
}

void treePostOrderExec(Node *N){
		if(N != NULL){
		treePostOrderExec(N->left);
		treePostOrderExec(N->right);
		printf("%d ", N->key);
	}
}

void treeClear(Tree *T){
	treeClearNodes(T->root);
	T->root = NULL;
}

void treeClearNodes(Node *N){
	if(N != NULL){
		treeClearNodes(N->left);
		treeClearNodes(N->right);
		free(N);
	}
}
