#include "treeBST.h"
#include <stdio.h>
#include <stdlib.h>

Node *treeWalk(Node *root, int key);
void treePrintWalk(Node *N, int depth);
Node *treeSearchRecursiveNode(Node *N, int key);
void treeNodePrint(Node *N, int depth);
Node *treeMinimum(Node *N);
void treeClearNode(Node *N);

void treeInit(Tree *T){
	T->root = NULL;
}

Node *treeSearchRecursive(Tree T, int key){
	return treeSearchRecursiveNode(T.root, key);
}

Node *treeSearchRecursiveNode(Node *N, int key){
	if(N == NULL){
		return NULL;
	}

	if(N->key == key){
		return N;
	}

	if(N->key > key){
		treeSearchRecursiveNode(N->left, key);
	}else{
		treeSearchRecursiveNode(N->right, key);
	}
}

Node *treeSearchIterative(Tree T, int key){
	Node *x = T.root;
	while(x->key != key){
		if(x->key >= key){
			x = x->left;
		}else{
			x = x->right;
		}
		
		if(x == NULL){
			return NULL;
		}
	}
	return x;
}

Node *treeSuccessor(Node *x){
	Node *y = (Node *)malloc(sizeof(Node));
	if(x->right != NULL){
		return treeMinimum(x->right);
	}
	y = x->p;
	while(y != NULL && x == y->right){
		x = y;
		y = y->p;
	}
	return y;
}

Node *treeMinimum(Node *N){
	Node *x = N;
	while(x->left != NULL){
		x = x->left;
	}
	return x;
}

void treeInsert(Tree *T, int key){
	Node *x = (Node *)malloc(sizeof(Node));
	Node *n = (Node *)malloc(sizeof(Node));
	
	if(T->root == NULL){
		x->key = key;
		x->p = NULL;
		x->left = NULL;
		x->right = NULL;
		T->root = x;
	}else{
		x = treeWalk(T->root, key);
		n->p = x;
		n->key = key;
		n->left = NULL;
		n->right = NULL;
		
		if(x->key >= key){
			x->left = n;
		}else{
			x->right = n;
		}
	}
}

Node *treeWalk(Node *root, int key){
	Node *x = (Node *)malloc(sizeof(Node));
	Node *walk = root;
	
	while(walk != NULL){
		x = walk;
		if(walk->key >= key){
			walk = walk->left;
		}else if(walk->key < key){
			walk = walk->right;
		}
	}
	
	return x;
}

void treeDelete(Tree *T, int key){
	Node *x = treeSearchRecursiveNode(T->root, key);
	Node *y = x->p;
	Node *tmp = (Node *)malloc(sizeof(Node));
	
	if(x->left == NULL && x->right == NULL){
		if(y->left == x){
			y->left = NULL;
		}else{
			y->right = NULL;
		}
	}else if( (x->left != NULL && x->right == NULL) ){
		x->left->p = y;
		if(y->left == x){
			y->left = x->left;
		}else{
			y->right = x->left;
		}
	}else if( (x->left == NULL && x->right != NULL) ){
		x->right->p = y;
		if(y->left == x){
			y->left = x->right;
		}else{
			y->right = x->right;
		}
	}else if( (x->left != NULL && x->right != NULL) ){
		tmp = treeSuccessor(x);
		x->key = tmp->key;
		
		if(tmp->right != NULL){
			tmp->p->left = tmp->right;
		}else{
			tmp->p->left = NULL;
		}
	}
	
	x->p = NULL;
	free(x);
}
	
void treePrint(Tree T){
	treePrintWalk(T.root, 0);
}

void treePrintWalk(Node *N, int depth){
	if(N != NULL){
		depth++;
		treePrintWalk(N->right, depth);
		
		treeNodePrint(N, depth);
		
		treePrintWalk(N->left, depth);	
	}
}

void treeNodePrint(Node *N, int depth){
	int i;
	for(i = 1; i < depth; i++){
		printf("\t");
	}
	printf("%d\n", N->key);
} 
	
void treeClear(Tree *T){
	treeClearNode(T->root);
	T->root = NULL;
}

void treeClearNode(Node *N){
	if(N != NULL){
		treeClearNode(N->left);
		treeClearNode(N->right);
		/*printf("Deleting node: %d\n", N->key);*/
		free(N);
	}
}

Node *treeSuccessorLowest(Tree *T){
	Node *x = treeMinimum(T->root);
	return treeSuccessor(x);
}
