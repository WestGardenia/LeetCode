#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>

typedef struct Binary_Tree TreeNode;

struct Binary_Tree{
	int val;
	TreeNode* lchild;
	TreeNode* rchild;
	int deep;
};

// 辅助队列数据结构和接口函数的定义与声明
#define element_type TreeNode*

typedef struct Queue Queue;

typedef struct QueueNode QueueNode;

struct Queue {
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
int Queue_IsEmpty(Queue* Q);
void QueueDestroy(Queue* Q);
void QueuePrint(Queue* Q);



TreeNode* TreeInit(TreeNode* RootNode);

TreeNode* NewTreeNode_Push(int val, TreeNode* lchild, TreeNode* rchild);

TreeNode* Tree_Creative();

void Binary_Tree_PreOrder(TreeNode* RootNode);

int MinDepth_DepthFirst(TreeNode* RootNode);	// 深度优先计算最小深度

int MinDepth_BreadthFirst(TreeNode* RootNode, Queue* Q);	// 广度优先计算最小深度




