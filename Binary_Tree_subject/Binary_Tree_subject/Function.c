#define _CRT_SECURE_NO_WARNINGS

#include"Binary_Tree.h"

Queue* QueueInit(Queue* Q)
{
	Q = (Queue*)malloc(sizeof(Queue));
	if (!Q)
	{
		return NULL;
		exit(-1);
	}
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
		// 如果队列中只有一个数值，那么就将队列的头尾都置空，并且直接返回队列指针，不要返回空指针，以免后续还要调用
		// 注意区别空队列和队列空指针
		Q->head = NULL;
		Q->tail = NULL;
		return Q;
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
	{
		printf("队列为空，无打印值！！！\n");
		return;
	}
		
	QueueNode* cur = Q->head;

	while (cur)
	{
		//printf("%d-> ", cur->data);
		printf("%d-> ", cur->data->val);
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

int Queue_IsEmpty(Queue* Q)
{
	if (Q->head == NULL)
		return 1;
	else
		return 0;
}
