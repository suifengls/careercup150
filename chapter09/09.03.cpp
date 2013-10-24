#include "../careercup.h"
using namespace std;

int findMagic(int a[], int s, int e)
{
    if(s > e)
	return -1;
    int mid = (s + e)/2;
    if(a[mid] == mid)
	return mid;
    else if(a[mid] < mid)
	return findMagic(a, mid+1, e);
    else
	return findMagic(a, s, mid-1);
}

int main()
{
    int a[] = {0, 2, 3, 4, 6, 7, 8, 10};
    cout << findMagic(a, 0, 7) << endl;
    return 0;
}
