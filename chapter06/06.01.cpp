#include "../careercup.h"
using namespace std;

int step(int n)
{
    if(n < 0)
	return 0;
    if(n == 1)
	return 1;
    return step(n-1) + step(n-2) + step(n-3);
}

int main()
{
    int n = 10;
    cout << "n = " << n << endl;
    cout << step(n) << endl;
    return 0;
}
