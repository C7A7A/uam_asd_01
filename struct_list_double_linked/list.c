#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void listInit(List *L){
	L->head = NULL;
	L->tail = NULL;
}

void listWrite(List L){
	Node *x = L.head;
	while(x != NULL){
		printf("%d ", x->key);
		x = x->next;
	}
	printf("\n");
}

void listInsert(List *L, int k){
	Node *x;
	x = (Node *)malloc(sizeof(Node));
	x->key = k;
	x->prev = NULL;
	
	if(L->head == NULL){
		x->next = NULL;
		L->head = x;
		L->tail = x;
	}else{
		x->next = L->head;
		L->head->prev = x;
		L->head = x;
	}
}

int listSearch(List L, int k){
	Node *x = L.head;
	while(x != NULL && x->key != k){
		x = x->next;
	}
	if(x != NULL){
		return x->key;
	}else{
		return -1;
	}
}

void listInsertAfter(List *L, int a, int b){
	Node *x = L->head;
	while(x != NULL && x->key != b){
		x = x->next;
	}
	if(x == NULL){
		printf("Nie znaleziono elementu: %d\n", b);
	}else{
		Node *y;
		y = (Node *)malloc(sizeof(Node));
		y->key = a;
		y->prev =  x;
		if(x->next != NULL){
			y->next = x->next;
		}else{
			y->next = NULL;
			L->tail = y;
		}
		x->next = y;
	}
}

void listDelete(List *L, int k){
	Node *x = L->head;
	while(x != NULL && x->key != k){
		x = x->next;
	}
	if(x == NULL){
		/*printf("Nie znaleziono elementu: %d\n", k);*/
	}else{
		x->prev->next = x->next;
		x->next->prev = x->prev;
		if((x->next) == NULL){
			L->tail = x->prev;
		}
		if((x->prev) == NULL){
			L->head = x->next;
		}
		free(x);
	}
}

void listInsertBefore(List *L, int a, int b){
	Node *x = L->head;
	while(x != NULL && x->key != b){
		x = x->next;
	}
	if(x == NULL){
		/*printf("Nie znaleziono elementu: %d\n", b);*/
	}else{
		Node *y;
		y = (Node *)malloc(sizeof(Node));
		y->key = a;
		y->next = x;
		if(x->prev != NULL){
			y->prev = x->prev;
		}else{
			y->prev = NULL;
			L->head = y;
		}
		x->prev = y;
	}
}

void listClear(List *L){
	Node *x = L->head;
	Node *tmp;
	while(x != NULL){
		tmp = x;
		x = x->next;
		free(tmp);
	}
	L->head = NULL;
	L->tail = NULL;
}

int listElementsIteratively(List L){
	Node *x = L.head;
	int elements = 0;
	while(x != NULL){
		elements++;
		x = x->next;
	}
	return elements;
}


int listElementsRecursively(Node *x){
	if(x == NULL){
		return 0;
	}else if((x->next) == NULL){
		return 1;
	}else{
		return listElementsRecursively(x->next) + 1;
	}
}

void listReverse(List *L){
	Node *element = L->head;
	Node *tmp;
	if(element != NULL){
		L->tail = element;
	}
	while(element != NULL){
		tmp = element->prev;
		element->prev = element->next;
		element->next = tmp;
		element = element->prev;
	}	
	if(tmp != NULL){
		L->head = tmp->prev;
	}
}
