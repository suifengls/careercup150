#ifndef _CAREERCUP_H_
#define _CAREERCUP_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <climits>

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

TreeNode *buildBST(int a[], int s, int e)
{
    if(s > e)
	return NULL;
    int mid = (s + e)/2;
    TreeNode *root = new TreeNode(a[mid]);
    root->left = buildBST(a, s, mid-1);
    root->right = buildBST(a, mid+1, e);
    return root;
}

void printTree(TreeNode *root)
{
    if(!root)
	std::cout <<  "# ";
    else
    {
	std::cout << root->val << " ";
	printTree(root->left);
	printTree(root->right);
    }
}

#endif
