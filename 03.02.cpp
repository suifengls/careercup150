#include "careercup.h"
using namespace std;

class stackmin
{
public:
    stackmin(int size = 100)
	{
	    buffer = new int[size];
	    minb = new int[size];
	    ptop = -1;
	    min = 0;
	    minb[0] = 10000;
	    this->size = size;
	}
    ~stackmin()
	{
	    delete [] buffer;
	    delete [] minb;
	}
    void push(int val)
	{
	    int index = ptop + 1;
	    if(index >= size)
		return;
	    buffer[index] = val;
	    if(empty())
		minb[index] = val;
	    else
	    {
		if(val <= mtop())
		  {
		    minb[min+1] = val;
		    ++min;
		  }
	    }
	    ++ptop;
	}
    void pop()
	{
	    if(!empty())
	      {
		if(top() == mtop())
		  --min;
		--ptop;
	      }
	}
    int top()
	{
	    if(!empty())
	    {
		return buffer[ptop];
	    }
	    return -1;
	}
    int mtop()
	{
	    if(!empty())
	    {
		return minb[min];
	    }
	    return 100000;
	}
    bool empty()
	{
	    return ptop == -1;
	}
private:
    int *buffer;
    int *minb;
    int ptop;
    int min;
    int size;
};

int main()
{
    stackmin mystack;
    for(int i = 0; i < 5; ++i)
    {
	mystack.push(15 - 3*i);
	cout << " stack.top: " << mystack.top() << " min: " << mystack.mtop() << endl;
    }
    mystack.push(3);
    cout << " stack.top: " << mystack.top() << " min: " << mystack.mtop() << endl;
    mystack.push(2);
    cout << " stack.top: " << mystack.top() << " min: " << mystack.mtop() << endl;
    mystack.push(4);
    cout << " stack.top: " << mystack.top() << " min: " << mystack.mtop() << endl;
    mystack.pop();
    mystack.pop();
    mystack.pop();
    mystack.pop();
    mystack.pop();
    mystack.pop();
    cout << " stack.top: " << mystack.top() << " min: " << mystack.mtop() << endl;

    return 0;
}
