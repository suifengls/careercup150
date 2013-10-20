#include "../careercup.h"
using namespace std;

class stack3
{
public:
    stack3(int size = 100)
	{
	    buffer = new int[size*3];
	    ptop[0] = ptop[1] = ptop[2] = -1;
	    this->size = size;
	}
    ~stack3()
	{
	    delete [] buffer;
	}
    void push(int stackNum, int val)
	{
	    int index = stackNum*size + ptop[stackNum] + 1;
	    if(index >= (stackNum+1)*size)
		return;
	    buffer[index] = val;
	    ++ptop[stackNum];
	}
    void pop(int stackNum)
	{
	    if(!empty(stackNum))
		--ptop[stackNum];
	}
    int top(int stackNum)
	{
	    if(!empty(stackNum))
	    {
		int index = stackNum*size + ptop[stackNum];
		return buffer[index];
	    }
	    return -1;
	}
    bool empty(int stackNum)
	{
	    return ptop[stackNum] == -1;
	}
private:
    int *buffer;
    int ptop[3];
    int size;
};

int main()
{
    stack3 mystack;
    for(int i = 0; i < 10; ++i)
	mystack.push(0, i);
    for(int i = 0; i < 30; ++i)
	mystack.push(1, i);
    for(int i = 0; i < 60; ++i)
	mystack.push(2, i);
    for(int i = 0; i < 3; ++i)
	cout << i << " stack.top: " << mystack.top(i) << endl;
    mystack.push(0, 111);
    mystack.pop(1);
    for(int i = 0; i < 3; ++i)
	cout << i << " stack.top: " << mystack.top(i) << endl;
    return 0;
}
