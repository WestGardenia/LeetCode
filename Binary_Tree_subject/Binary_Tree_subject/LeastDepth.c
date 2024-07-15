#define _CRT_SECURE_NO_WARNINGS

#include"Binary_Tree.h"

TreeNode* TreeInit(TreeNode* RootNode)
{
	RootNode = (TreeNode*)malloc(sizeof(TreeNode));
	assert(RootNode);

	RootNode->val = INT_MAX;
	RootNode->lchild = NULL;
	RootNode->rchild = NULL;
	RootNode->deep = 0;

	return RootNode;
}

TreeNode* NewTreeNode_Push(int val, TreeNode* lchild, TreeNode* rchild)
{
	TreeNode* newnode = NULL;
	newnode =  TreeInit(newnode);
	newnode->lchild = lchild;
	newnode->rchild = rchild;
	newnode->val = val;

	return newnode;
}

TreeNode* Tree_Creative()
{
	// 构建这样一颗二叉树
	//			1
	//		2		3
	//	  4   5   6
	//			   7
	// 
	// 先序遍历为： 1	2	4	5	3	6	7
	//
	TreeNode* node7 = NewTreeNode_Push(7, NULL, NULL);
	TreeNode* node6 = NewTreeNode_Push(6, node7, NULL);
	TreeNode* node5 = NewTreeNode_Push(5, NULL, NULL);
	TreeNode* node4 = NewTreeNode_Push(4, NULL, NULL);
	TreeNode* node3 = NewTreeNode_Push(3, node6, NULL);
	TreeNode* node2 = NewTreeNode_Push(2, node4, node5);
	TreeNode* node1 = NewTreeNode_Push(1, node2, node3);

	return node1;
}

void Binary_Tree_PreOrder(TreeNode* RootNode)
{
	if (RootNode)
	{
		printf("%d->", RootNode->val);
		Binary_Tree_PreOrder(RootNode->lchild);
		Binary_Tree_PreOrder(RootNode->rchild);
	}

}

int MinDepth_DepthFirst(TreeNode* RootNode)
{
	// 深度优先计算最小深度思想：
	// 1.只要访问的结点不是叶子节点，则深度+1，并继续向下访问其孩子节点
	// 2.直到访问到孩子节点为止
	// 判断：如果树为空，则深度为0，直接返回
	if (!RootNode)
		return 0;
	// 判断：如果是叶子节点，则其深度为1，直接返回
	if (!RootNode->lchild && !RootNode->rchild)
		return 1;
	int min = INT_MAX;
	if (RootNode->lchild)
	{
		min = (int)fmin(MinDepth_DepthFirst(RootNode->lchild), min);
	}
	if (RootNode->rchild)
	{
		min = (int)fmin(MinDepth_DepthFirst(RootNode->rchild), min);
	}
	return (min + 1);
}

int MinDepth_BreadthFirst(TreeNode* RootNode, Queue* Q)	// 广度优先计算最小深度
{
	// 算法思想：
	// 1.将传入参数结点入队，并将传入初始节点的deep值设为1
	// 2.判断其是否有左右孩子，如果有，deep值在父节点的基础上加1，并入队
	// 3.出队队尾值，并判断是否为叶子节点，如果是叶子节点，则将其deep值返回；如果不是，就将继续循环
	if (RootNode == NULL)
	{
		return 0;
	}
	Q = QueuePush(Q, RootNode);
	RootNode->deep = 1;

	while (!Queue_IsEmpty(Q))
	{
		TreeNode* newnode = QueuePop(Q)->data;
		// 每次出队一个值需要将队列头的值删除
		Q = QueueDelate(Q);
		if (newnode->lchild == NULL && newnode->rchild == NULL)
			return newnode->deep;
		if (newnode->lchild != NULL)
		{
			newnode->lchild->deep = newnode->deep + 1;
			Q = QueuePush(Q, newnode->lchild);
		}
		if (newnode->rchild != NULL)
		{
			newnode->rchild->deep = newnode->deep + 1;
			Q = QueuePush(Q, newnode->rchild);
		}
	}
	// 如果循环结束，代表队列为空，再返回0；
	// 注意区别循环返回和循环结束返回
	return 0;
}