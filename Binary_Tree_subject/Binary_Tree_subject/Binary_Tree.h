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
};

TreeNode* TreeInit(TreeNode* RootNode);

TreeNode* NewTreeNode_Push(int val, TreeNode* lchild, TreeNode* rchild);

TreeNode* Tree_Creative();

void Binary_Tree_PreOrder(TreeNode* RootNode);

int MinDepth_DepthFirst(TreeNode* RootNode);
