#include "../careercup.h"
using namespace std;

int fetch(int a[], int i, int j)
{
    return (a[i] >> j) & 1;
}

int get(int a[], int i)
{
    int num = 0;
    for(int j = 31; j >= 0; --j)
	num = (num << 1) | fetch(a, i, j);
    return num;
}

int missing(int a[], int n)
{
    int xor1 = 0, xor2 = 0;
    for(int i = 0; i <= n; ++i)
    {
	xor1 ^= i;
	if(i == n)
	    break;
	xor2 ^= get(a, i);
    }
    return xor1^xor2;
}

int main()
{
    int a[] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 10};
    cout << "Missing number : " << missing(a, 10) << endl;
    return 0;
}
