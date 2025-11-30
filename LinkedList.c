#include <stdlib.h>
#include "LinkedList.h"

LinkedList* init_list() {
	LinkedList* L = (LinkedList*)malloc(sizeof(LinkedList));
	L->head = NULL;
	L->count = 0;
	return L;
}


Node* make_node(int v) {
	Node* N = (Node*)malloc(sizeof(Node));
	N->v = v;
	N->next = NULL;
	return N;
}

void linked_insert(LinkedList* L, int v) {
	Node* N = make_node(v);
	N->next = L->head;
	L->head = N;
	L->count++;
}