#define _CRT_SECURE_NO_WARNINGS
#include"Binary_Tree.h"

static void test_01()
{
	TreeNode* RootNode = NULL;
	RootNode = Tree_Creative();

	Binary_Tree_PreOrder(RootNode);
}

void test_02()
{
	TreeNode* RootNode = NULL;
	RootNode = Tree_Creative();

	int min_DepthFirst = MinDepth_DepthFirst(RootNode);

	printf("\n这棵树的最小深度是：%d\n", min_DepthFirst);
}


int main()
{
	test_01();
	test_02();
	return 0;
}