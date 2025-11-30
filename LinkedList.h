#pragma once

typedef struct Node {
	int v;
	struct Node* next;
}Node;

typedef struct LinkedList {
	Node* head;
	int count;
}LinkedList;

LinkedList* init_list();

Node* make_node(int v);

void linked_insert(LinkedList* L, int v);