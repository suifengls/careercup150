#include "careercup.h"
using namespace std;

void removeDup1(ListNode *head)
{
    if(!head || !head->next)
	return;
    map<int, bool> dup;
    ListNode *node = head;
    dup[head->val] = true;
    while(node->next)
    {
	if(dup.count(node->next->val) > 0)
	{
	    ListNode *tmp = node->next;
	    node->next = node->next->next;
	    delete tmp;
	}
	else
	{
	    dup[node->next->val] = true;
	    node = node->next;
	}
    }
}

void removeDup2(ListNode *head)
{
    if(!head || !head->next)
	return;
    ListNode *curr = head;
    while(curr)
    {
	ListNode *node = curr;
	while(node->next)
	{
	    if(curr->val == node->next->val)
	    {
		ListNode *tmp = node->next;
		node->next = node->next->next;
		delete tmp;
	    }
	    else
		node = node->next;
	}
	curr = curr->next;
    }
}

int main()
{
    int len = 8;
    int a[] = {1, 3, 2, 2, 1, 4, 2, 1};
    ListNode *head1 = buildList(a, len);
    ListNode *head2 = buildList(a, len);
    printList(head1);
    removeDup1(head1);
    cout << "Remove duplicates hashtable:" << endl;
    printList(head1);
    removeDup2(head2);
    cout << "Remove duplicates no extra space:" << endl;
    printList(head2);
    return 0;
}
