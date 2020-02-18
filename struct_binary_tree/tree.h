#ifndef TREE_H
#define TREE_H

struct node;

typedef
struct node{
	int key;
	struct node *p;
	struct node *left;
	struct node *right;
}
Node;

typedef
struct tree{
	Node *root;
}
Tree;

void treeInit(Tree *T);
void treeMake(Tree *T, int k);
void treePrint(Tree T);
void treePreOrder(Tree T);
void treeInOrder(Tree T);
void treePostOrder(Tree T);
void treeClear(Tree *T);
#endif
