#include "careercup.h"
using namespace std;

void hanoi(int n, char src, char md, char dst)
{
    if(n == 1)
	cout << "Disk 1 " << src << " -> " << dst << endl;
    else
    {
	hanoi(n-1, src, dst, md);
	cout << "Disk " << n << " " << src << " -> " << dst << endl;
	hanoi(n-1, md, src, dst);
    }
}

class Tower
{
public:
    Tower(char c)
	{
	    index = c;
	}
    char getIndex()
	{
	    return index;
	}
    void add(int i)
	{
	    disks.push(i);
	}
    void moveTop(Tower *to)
	{
	    int topD = disks.top();
	    disks.pop();
	    to->add(topD);
	    cout << "Disk " << topD << " " << index << " -> " << to->getIndex() << endl;
	}
    void hanoi(int n, Tower *dst, Tower *md)
	{
	    if(n == 1)
		moveTop(dst);
	    else
	    {
		hanoi(n-1, md, dst);
		moveTop(dst);
		md->hanoi(n-1, dst, this);
	    }
	}
private:
    char index;
    stack<int> disks;
};

int main()
{
    int n = 3;
    cout << "Recusive :" << endl;
    hanoi(3, 'A', 'B', 'C');
    cout << "Stack :" << endl;
    Tower *tower1 = new Tower('A');
    Tower *tower2 = new Tower('B');
    Tower *tower3 = new Tower('C');
    for(int i = n; i > 0; --i)
	tower1->add(i);
    tower1->hanoi(n, tower3, tower2);
    return 0;
}
