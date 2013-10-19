#ifndef _CAREERCUP_H_
#define _CAREERCUP_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

typedef struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}ListNode;

typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

void printList(ListNode *head)
{
    while(head)
    {
	std::cout << head->val << " -> ";
	head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

ListNode *buildList(int a[], int len)
{
    ListNode *head, *node;
    for(int i = 0; i < len; ++i)
    {
	ListNode *tmp = new ListNode(a[i]);
	if(i == 0)
	{
	    head = tmp;
	    node = head;
	    continue;
	}
	node->next = tmp;
	node = tmp;
    }
    return head;
}
	
#endif
