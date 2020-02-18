#ifndef TREEBST_H
#define TREEBST_H

struct node;

typedef
struct node{
	int key;
	struct node *p;
	struct node *left;
	struct node *right;
}Node;

typedef
struct treeBST{
	Node *root;
}Tree;

void treeInit(Tree *T);
void treePrint(Tree T);

Node *treeSearchRecursive(Tree T, int key);
Node *treeSearchIterative(Tree T, int key);
Node *treeSuccessor(Node *x);
void treeInsert(Tree *T, int key);
void treeDelete(Tree *T, int key);
void treeClear(Tree *T);

Node *treeSuccessorLowest(Tree *T);

#endif
