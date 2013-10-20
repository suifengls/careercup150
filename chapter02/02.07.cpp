#include "../careercup.h"
using namespace std;

bool isPalindrome(ListNode *head)
{
    if(!head || !head->next)
	return true;
    ListNode *fast = head, *slow = head;
    stack<int> stk;
    while(fast && fast->next)
    {
	fast = fast->next->next;
	stk.push(slow->val);
	slow = slow->next;
    }
    if(fast)
	slow = slow->next;
    while(slow)
    {
	if(slow->val != stk.top())
	    return false;
	stk.pop();
	slow = slow->next;
    }
    return true;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    ListNode *head1 = buildList(a, 8);
    printList(head1);
    cout << " Is palindrome? " << isPalindrome(head1) << endl;
    int b[] = {1, 2, 3, 4, 3, 2, 1};
    ListNode *head2 = buildList(b, 7);
    printList(head2);
    cout << " Is palindrome? " << isPalindrome(head2) << endl;
    int c[] = {1, 2, 3, 3, 2, 1};
    ListNode *head3 = buildList(c, 6);
    printList(head3);
    cout << " Is palindrome? " << isPalindrome(head3) << endl;
    return 0;
}
