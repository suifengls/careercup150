#include "careercup.h"
using namespace std;

stack<int> sortStack(stack<int> s)
{
    stack<int> ads;
    while(!s.empty())
    {
	int curr = s.top();
	s.pop();
	while(!ads.empty() && curr < ads.top())
	{
	    s.push(ads.top());
	    ads.pop();
	}
	ads.push(curr);
    }
    return ads;
}

int main()
{
    stack<int> stk;
    stk.push(1);
    stk.push(4);
    stk.push(3);
    stk.push(5);
    stk.push(2);
    stack<int> sstk = sortStack(stk);
    while(!sstk.empty())
    {
	cout << sstk.top() << endl;
	sstk.pop();
    }
    return 0;
}
