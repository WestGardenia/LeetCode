#define _CRT_SECURE_NO_WARNINGS

#include"Queue.h"


Queue* QueueInit(Queue* Q)
{
	Q = (Queue*)malloc(sizeof(Queue));
	Q->head = NULL;
	Q->tail = NULL;



	return Q;
}

QueueNode* QueuePop(Queue* Q)
{
	return Q->tail;
}

Queue* QueueDelate(Queue* Q)
{
	if (Q->head == NULL)
		return NULL;
	QueueNode* cur = Q->head;
	if (Q->head == Q->tail)
	{
		Q->tail = NULL;
		return NULL;
	}
	while (cur->next != Q->tail)
	{
		cur = cur->next;
	}

	Q->tail = cur;
	cur->next = NULL;

	return Q;
}

Queue* QueuePush(Queue* Q, element_type val)
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		return NULL;
		exit(-1);
	}
	newnode->data = val;
	newnode->next = Q->head;
	if (Q->head == NULL)
	{
		Q->tail = newnode;
		Q->head = newnode;
	}

	Q->head = newnode;
	return Q;
}

void QueuePrint(Queue* Q)
{
	if (!Q)
		return;
	QueueNode* cur = Q->head;

	while (cur)
	{
		printf("%d-> ", cur->data);
		cur = cur->next;
	}
}

void QueueDestroy(Queue* Q)
{
	QueueNode* cur = Q->head;
	QueueNode* delate = Q->head;

	while (cur)
	{
		delate = cur;
		cur = cur->next;
		free(delate);
	}
	printf("\n");
}

