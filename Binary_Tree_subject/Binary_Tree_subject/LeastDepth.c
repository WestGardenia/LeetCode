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
	// ��������һ�Ŷ�����
	//			1
	//		2		3
	//	  4   5   6
	//			   7
	// 
	// �������Ϊ�� 1	2	4	5	3	6	7
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
	// ������ȼ�����С���˼�룺
	// 1.ֻҪ���ʵĽ�㲻��Ҷ�ӽڵ㣬�����+1�����������·����亢�ӽڵ�
	// 2.ֱ�����ʵ����ӽڵ�Ϊֹ
	// �жϣ������Ϊ�գ������Ϊ0��ֱ�ӷ���
	if (!RootNode)
		return 0;
	// �жϣ������Ҷ�ӽڵ㣬�������Ϊ1��ֱ�ӷ���
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

int MinDepth_BreadthFirst(TreeNode* RootNode, Queue* Q)	// ������ȼ�����С���
{
	// �㷨˼�룺
	// 1.��������������ӣ����������ʼ�ڵ��deepֵ��Ϊ1
	// 2.�ж����Ƿ������Һ��ӣ�����У�deepֵ�ڸ��ڵ�Ļ����ϼ�1�������
	// 3.���Ӷ�βֵ�����ж��Ƿ�ΪҶ�ӽڵ㣬�����Ҷ�ӽڵ㣬����deepֵ���أ�������ǣ��ͽ�����ѭ��
	if (RootNode == NULL)
	{
		return 0;
	}
	Q = QueuePush(Q, RootNode);
	RootNode->deep = 1;

	while (!Queue_IsEmpty(Q))
	{
		TreeNode* newnode = QueuePop(Q)->data;
		// ÿ�γ���һ��ֵ��Ҫ������ͷ��ֵɾ��
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
	// ���ѭ���������������Ϊ�գ��ٷ���0��
	// ע������ѭ�����غ�ѭ����������
	return 0;
}