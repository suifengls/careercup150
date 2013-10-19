#include "careercup.h"
using namespace std;

ListNode *findBeginning(ListNode *head)
{
    if(!head)
	return NULL;
    ListNode *fast = head, *slow = head;
    do
    {
	fast = fast->next->next;
	slow = slow->next;
    }while(fast != slow);
    slow = head;
    while(fast != slow)
    {
	fast = fast->next;
	slow = slow->next;
    }
    return fast;
}

int main()
{
    int len = 8;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    ListNode *head = buildList(a, len);
    ListNode *node = head;
    printList(head);
    while(node->next)
	node = node->next;
    node->next = head->next->next->next->next;
    ListNode *begin = findBeginning(head);
    cout << begin->val << endl;
    return 0;
}
