#include "../careercup.h"
using namespace std;

class Myqueue
{
public:
    void enqueue(int val)
    {
	stack2.push(val);
    }
    void dequeue()
    {
	if(stack1.empty())
	{
	    while(!stack2.empty())
	    {
		stack1.push(stack2.top());
		stack2.pop();
	    }
	}
	stack1.pop();
    }
    int peek()
    {
	if(stack1.empty())
	{
	    while(!stack2.empty())
	    {
		stack1.push(stack2.top());
		stack2.pop();
	    }
	}
	return stack1.top();
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};

int main()
{
    Myqueue myq;
    for(int i = 0; i < 10; ++i)	
	myq.enqueue(i);
    myq.dequeue();
    myq.dequeue();
    myq.dequeue();
    for(int i = 0; i < 5; ++i)	
	myq.enqueue(i);
    cout << "Myqueue:" << endl;
    for(int i = 0; i < 12; ++i)
    {
	cout << myq.peek() << " ";
	myq.dequeue();
    }
    cout << endl;
    return 0;
}
