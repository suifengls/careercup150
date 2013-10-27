#include "../careercup.h"
using namespace std;

int findDecrease(int a[], int n)
{
    int i;
    for(i = 1; i < n; ++i)
	if(a[i] < a[i-1])
	    return i-1;
    return n-1;
}

int findIncrease(int a[], int n)
{
    int j;
    for(j = n-2; j >= 0; --j)
	if(a[j] > a[j+1])
	    return j+1;
    return 0;
}

void findSequence(int a[], int n, int &i, int &j)
{
    int left = findDecrease(a, n);
    int right = findIncrease(a, n);

    ++left;
    if(left >= n)
	return;
    --right;
    for(int k = left; k <= right; ++k)
    {
	if(a[k] < a[left])
	    left = k;
	if(a[k] > a[right])
	    right = k;
    }

    for(i = 0; i <= left; ++i)
	if(a[i] > a[left])
	    break;
    for(j = n-1; j >= right; --j)
	if(a[j] < a[right])
	    break;
    return;
}

int main()
{
    int a[] = {1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
    int n = 13;
    int i = 0;
    int j = n-1;

    findSequence(a, n, i, j);

    cout << i << " and " << j << endl;
    
    return 0;
}
