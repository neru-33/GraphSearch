#pragma once
#define QUEUE_SIZE 50

typedef struct CircularQueue {
	int B[QUEUE_SIZE];
	int front;
	int rear;
	int size;
}Queue;

Queue* init_queue();
int queue_full(Queue* Q);
int queue_empty(Queue* Q);
void enqueue(Queue* Q, int V);
int dequeue(Queue* Q);
int queue_front(Queue* Q);
