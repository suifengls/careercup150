#include "../careercup.h"
using namespace std;

int insert(int N, int M, int j, int i)
{
    int mask = ~((((1 << (j+1)) - 1) >> i) << i);
    return (N & mask) | (M << i);
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
    int N = 1 << 10, M = 21;

    cout << "Insert " << endl;
    printbit(M);
    cout << " to " << endl;
    printbit(N);
    cout << " -> " << endl;
    printbit(insert(N, M, 6, 2));
    return 0;
}
