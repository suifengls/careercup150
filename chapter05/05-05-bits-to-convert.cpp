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

void convert(int A, int B)
{
    cout << "Convert from " << A << " to " << B << " requires " << countone(A^B) << " bits of changes." << endl;
}

int main()
{
    convert(31, 10);
    return 0;
}
