#include "careercup.h"
using namespace std;

ListNode *addTwo1(ListNode *a, ListNode *b)
{
    if(!a && !b)
	return NULL;
    else if(!a)
	return b;
    else if(!b)
	return a;
    ListNode *head = NULL, *node = NULL;
    int carry = 0;
    while(a || b || carry)
    {
	int n1 = 0, n2 = 0;
	if(a)
	{
	    n1 = a->val;
	    a = a->next;
	}
	if(b)
	{
	    n2 = b->val;
	    b = b->next;
	}
	int sum = n1 + n2 + carry;
	carry = sum/10;
	ListNode *tmp = new ListNode(sum%10);
	if(!head)
	{
	    head = tmp;
	    node = head;
	}
	else
	{
	    node->next = tmp;
	    node = node->next;
	}
    }
    return head;
}

ListNode *addZero(ListNode *head, int n)
{
    while(n > 0)
    {
	ListNode *tmp = new ListNode(0);
	tmp->next = head;
	head = tmp;
	--n;
    }
    return head;
}

ListNode *addTwo2(ListNode *a, ListNode *b)
{
    if(!a && !b)
	return NULL;
    else if(!a)
	return b;
    else if(!b)
	return a;
    int la = 0, lb = 0;
    ListNode *ha = a, *hb = b;
    while(a)
    {
	++la;
	a = a->next;
    }
    while(b)
    {
	++lb;
	b = b->next;
    }
    a = ha; b= hb;
    if(la < lb)
    {
	a = addZero(a, lb-la+1);
	b = addZero(b, 1);
    }
    else if(la > lb)
    {
	a = addZero(a, 1);
	b = addZero(b, la-lb+1);
    }
    ha = a;
    hb = b;
    ListNode *hc = NULL;
    hc = addZero(hc, max(la,lb)+1);
    ListNode *p = hc, *q = hc, *c = hc;
    while(a->next && b->next)
    {
	q = q->next;
	int sum = a->next->val + b->next->val;
	q->val = sum % 10;
	if(sum > 9)
	{
	    p->val++;
	    for(p = p->next; p != q; p=p->next)
		p->val = 0;
	}
	else if(sum < 9)
	{
	    p = q;
	}
	a = a->next;
	b = b->next;
    }
    if(hc->val)
	return hc;
    else
	return hc->next;
}    

int main()
{
    int n1[] = {9, 9, 9, 9};
    int n2[] = {1};
    ListNode *a = buildList(n1, 4);
    ListNode *b = buildList(n2, 1);
    ListNode *c = addTwo2(a, b);
    printList(a);
    printList(b);
    printList(c);
    return 0;
}
