#include "Queue.h"
#include <stdlib.h>

Queue* init_queue() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->front = Q->rear = 0;
	Q->size = QUEUE_SIZE;
	return Q;
}

int queue_full(Queue* Q) {
	return (Q->rear + 1) % QUEUE_SIZE == Q->front;
}

int queue_empty(Queue* Q) {
	return Q->front == Q->rear;
}


void enqueue(Queue* Q, int V) {
	if (!queue_full(Q)) {
		Q->rear = (Q->rear + 1) % QUEUE_SIZE;
		Q->B[Q->rear] = V;
	}
}

int dequeue(Queue* Q) {
	if (!queue_empty(Q)) {
		Q->front = (Q->front + 1) % QUEUE_SIZE;
		return Q->B[Q->front];
	}
}

int queue_front(Queue* Q) {
	if (!queue_empty(Q)) {
		int front = (Q->front + 1) % QUEUE_SIZE;
		return Q->B[front];
	}
}
