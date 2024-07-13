#pragma once
#include"Binary_Tree.h"

#define element_type int

typedef struct Queue Queue;

typedef struct QueueNode QueueNode;

struct Queue{
	QueueNode* head;
	QueueNode* tail;
};

struct QueueNode {
	QueueNode* next;
	element_type data;
};


Queue* QueueInit(Queue* Q);

QueueNode* QueuePop(Queue* Q);

Queue* QueueDelate(Queue* Q);

Queue* QueuePush(Queue* Q, element_type val);

void QueueDestroy(Queue* Q);

void QueuePrint(Queue* Q);