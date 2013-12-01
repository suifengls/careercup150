#include "../careercup.h"
using namespace std;

int swapBit(int x)
{
    int mask = 0x55555555;
    return ((x & mask) << 1) | ((x >> 1) & mask);
}

void printbit(int n)
{
    vector<int> v;
    int mask = 1;
    int len = 4 * sizeof(int);
    while(len--)
    {
	if(n & mask)
	    v.push_back(1);
	else
	    v.push_back(0);
	mask = mask << 1;
    }
    while(!v.empty())
    {
	cout << v.back();
	v.pop_back();
    }
    cout << endl;
}

int main()
{
    int x = 0x120bc27e;
    printbit(x);
    cout << " swap to " << endl;
    printbit(swapBit(x));
    return 0;
}
