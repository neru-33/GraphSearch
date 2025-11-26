#pragma once

typedef struct Node {
	int V;
	struct Node* next;
}Node;

typedef struct LinkedList {
	Node* head;
	int count;
}LinkedList;

LinkedList* init_list();

Node* make_node(int V);

void linked_insert(LinkedList* L, int V);