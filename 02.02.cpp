#include "careercup.h"
using namespace std;

ListNode *findkNode(ListNode *head, int k)
{
    if(!head)
	return NULL;
    ListNode *curr = head;
    ListNode *kn = head;
    while(k > 0 && curr)
    {
	curr = curr->next;
	--k;
    }
    if(k > 0)
	return NULL;
    while(curr)
    {
	curr = curr->next;
	kn = kn->next;
    }
    return kn;
}

int main()
{
    int len = 8;
    int a[] = {8, 7, 6, 5, 4, 3, 2, 1};
    ListNode *head = buildList(a, len);
    printList(head);
    cout << "The 8th to last: " << findkNode(head, 8)->val << endl;
    cout << "The 1st to last: " << findkNode(head, 1)->val << endl;
    cout << "The 4th to last: " << findkNode(head, 4)->val << endl;
    if(!findkNode(head, 10))
	cout << "The 10th to last node does not exist!"  << endl;
    return 0;
}
