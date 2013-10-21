#include "../careercup.h"
using namespace std;

int countone(int n)
{
    int cnt = 0;
    for(int i = 0; i < 32; ++i)
    {
	if(n & 1)
	    ++cnt;
	n >>= 1;
    }
    return cnt;
}

void findNext(int n)
{
    cout << "Find for " << n << endl;
    int num = countone(n);
    if(n == -1 || num == 0)
	return;
    int l = n + 1, s = n - 1;
    for(; countone(l) != num && l < INT_MAX; ++l);
    if(countone(l) == num)
	cout << "Next largest " << l << endl;

    for(; countone(s) != num && s > INT_MIN; --s);
	if(countone(s) == num)
	    cout << "Next smallest " << s << endl;
}

int main()
{
    findNext(-33);
    return 0;
}
