#define _CRT_SECURE_NO_WARNINGS
#include"Leetcode.h"

void test_01()
{
	int arr[5] = { 5,10,5,10,20 };
	bool B = lemonadeChange(arr, sizeof(arr) / sizeof(int));
	B ? printf("True") : printf("False");
}

int main()
{
	test_01();
	return 0;
}