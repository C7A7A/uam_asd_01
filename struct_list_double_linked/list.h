#ifndef LIST_H
#define LIST_H
struct node;

typedef
struct node{
	int key;
	struct node *next;
	struct node *prev;
}
Node;

typedef
struct list{
	Node *head;
	Node *tail;
}
List;

void listInit(List *L);
void listWrite(List L);
void listInsert(List *L, int k);
int listSearch(List L, int k);
void listInsertAfter(List *L, int a, int b);
void listDelete(List *L, int k);
void listInsertBefore(List *L, int a, int b);
void listClear(List *L);
int listElementsIteratively(List L);
int listElementsRecursively(Node *x);
void listReverse(List *L);


#endif
