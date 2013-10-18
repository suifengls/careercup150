#include "careercup.h"
using namespace std;

void removeMNode(ListNode *mid)
{
    if(!mid || !mid->next)
	return;
    ListNode *tmp = mid->next;
    mid->next = tmp->next;
    mid->val = tmp->val;
    delete tmp;
}

int main()
{
    int len = 8;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    ListNode *head = buildList(a, len);
    ListNode *mid = head;
    printList(head);
    for(int i = 1; i < 6; ++i)
	mid = mid->next;
    cout << "Remove 6th node: " << endl;
    removeMNode(mid);
    printList(head);
    return 0;
}
