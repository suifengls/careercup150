#include "careercup.h"
using namespace std;

ListNode *partitionList(ListNode *head, int x)
{
    if(!head || !head->next)
	return head;
    ListNode *left = NULL, *lhead = NULL, *right = NULL, *rhead = NULL;
    while(head)
    {
	if(head->val < x)
	{
	    ListNode *tmp = new ListNode(head->val);
	    if(!lhead)
	    {
		lhead = tmp;
		left = lhead;
	    }
	    else
	    {
		left->next = tmp;
		left = left->next;
	    }
	}
	else
	{
	    ListNode *tmp = new ListNode(head->val);
	    if(!rhead)
	    {
		rhead = tmp;
		right = rhead;
	    }
	    else
	    {
		right->next = tmp;
		right = right->next;
	    }
	}
	head = head->next;
    }
    if(!lhead)
	return rhead;
    if(!rhead)
	return lhead;
    left->next = rhead;
    return lhead;
}

int main()
{
    int len = 8;
    int a[] = {1, 2, 3, 4, 1, 2, 2, 4};
    ListNode *head = buildList(a, len);
    printList(head);
    cout << " Partition by 3 " << endl;
    ListNode *partition = partitionList(head, 3);
    printList(partition);
    return 0;
}
