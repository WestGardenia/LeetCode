#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode* next;
};


// ˳�����
struct sqList {
    int* data;
    int length;
};


struct ListNode* deleteNode(struct ListNode* head, int val);    // ɾ��ָ���ڵ�

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2); // �ϲ��������� 

void Reverse_spList(struct sqList *SL);
