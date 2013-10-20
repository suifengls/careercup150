#include <iostream>
using namespace std;

class stack
{
public:
    stack(int size = 10)
	{
	    buffer = new int[size];
	    ptop = -1;
	    this->size = size;
	}
    ~stack()
	{
	    delete [] buffer;
	}
    void push(int val)
	{
	    if(ptop+1 < size)
	    {
		++ptop;
		buffer[ptop] = val;
	    }
	}
    void pop()
	{
	    if(!empty())
		--ptop;
	}
    int top()
	{
	    if(!empty())
		return buffer[ptop];
	    return -1;
	}
    bool empty()
	{
	    return ptop == -1;
	}
    bool full()
	{
	    return ptop == size - 1;
	}
private:
    int *buffer;
    int ptop;
    int size;
};
 
class SetOfStacks
{
public:
    SetOfStacks(int cap = 10)
	{
	    st = new stack[cap];
	    curr = 0;
	    capacity = cap;
	}
    ~SetOfStacks()
	{
	    delete [] st;
	}
    void push(int val)
	{
	    if(st[curr].full())
		++curr;
	    if(curr >= capacity)
		return;
	    st[curr].push(val);
	}
    void pop()
	{
	    if(st[curr].empty())
		--curr;
	    if(curr < 0)
		return;
	    st[curr].pop();
	}
    int top()
	{
	    if(st[curr].empty())
		--curr;
	    if(curr < 0)
		return -1;
	    return st[curr].top();
	}
    bool empty()
	{
	    if(curr == 0)
		return st[0].empty();
	    else
		return false;
	}
    bool full()
	{
	    if(curr == capacity-1)
		return st[curr].full();
	    else
		return false;
	}
private:
    stack *st;
    int curr;
    int capacity;
};

class SetOfStacksAt
{
public:
    SetOfStacksAt(int cap = 10)
	{
	    st = new stack[cap];
	    curr = 0;
	    capacity = cap;
	}
    ~SetOfStacksAt()
	{
	    delete [] st;
	}
    void push(int val)
	{
	    if(st[curr].full())
		++curr;
	    if(curr >= capacity)
		return;
	    st[curr].push(val);
	}
    void pop()
	{
	    while(st[curr].empty() && curr >= 0)
		--curr;
	    if(curr < 0)
		return;
	    st[curr].pop();
	}
    void popAt(int i)
	{
	    if(st[i].empty())
		return;
	    else
		st[i].pop();
	}
    int top()
	{
	    while(st[curr].empty() && curr >= 0)
		--curr;
	    if(curr < 0)
		return -1;
	    return st[curr].top();
	}
    bool empty()
	{
	    if(st[curr].empty() && curr >= 0)
		--curr;
	    if(curr == -1)
		return true;
	    else
		return false;
	}
    bool full()
	{
	    if(curr == capacity-1)
		return st[curr].full();
	    else
		return false;
	}
private:
    stack *st;
    int curr;
    int capacity;
};

int main()
{
    SetOfStacks ss(5);
    for(int i = 0; i < 35; ++i)
    {
	ss.push(i);
    }
    cout << " ss.push: " << ss.top() << endl;
    for(int i = 0; i < 12; ++i)
    {
	ss.pop();
    }
    cout << " ss.pop: " << ss.top() << endl;
    SetOfStacksAt ssa(5);
    for(int i = 0; i < 35; ++i)
    {
	ssa.push(i);
    }
    cout << " ssa.push: " << ssa.top() << endl;
    for(int i = 0; i < 8; ++i)
    {
	ssa.popAt(1);
    }
    for(int i = 0; i < 20; ++i)
    {
	ssa.pop();
	cout << " ssa.pop: " << ssa.top() << endl;
    }
    return 0;
}
