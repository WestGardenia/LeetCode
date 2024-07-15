#define _CRT_SECURE_NO_WARNINGS
#include"Binary_Tree.h"

// ��������������ʾ��
static void test_01()
{
	TreeNode* RootNode = NULL;
	RootNode = Tree_Creative();

	Binary_Tree_PreOrder(RootNode);
}


// �������в�������
//static void test_02()
//{
//#define element_type int
//	Queue* Q = NULL;
//	Q = QueueInit(Q);
//
//	Q = QueuePush(Q, 1);
//	Q = QueuePush(Q, 2);
//	Q = QueuePush(Q, 3);
//	Q = QueuePush(Q, 4);
//	Q = QueuePush(Q, 5);
//	Q = QueuePush(Q, 6);
//
//	QueuePrint(Q);
//	int m[10] = { 0 };	
//	printf("\n����ɾ���������ԣ�");
//	for (int i = 0; i < sizeof(m)/sizeof(int); i++)
//	{
//		m[i] = QueuePop(Q)->data;
//		Q = QueueDelate(Q);
//		printf("%d ", m[i]);
//		if (!Q)
//			break;
//
//	}
//	printf("\n");
//	QueuePrint(Q);
//}


// ���������С���----�������/�������----��������
static void test_03()
{
	TreeNode* RootNode = NULL;
	RootNode = Tree_Creative();

	int min_DepthFirst = MinDepth_DepthFirst(RootNode);

	printf("���������С����ǣ�%d\n", min_DepthFirst);


	Queue* Q = NULL;
	Q = QueueInit(Q);
	int min_BreathFirst = MinDepth_BreadthFirst(RootNode, Q);
	printf("���������С����ǣ�%d\n", min_BreathFirst);
}




int main()
{
	//test_01();
	//test_02();
	test_03();
	return 0;
}