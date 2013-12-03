#include "../careercup.h"
using namespace std;

int findIndex(int a[], int target, int s, int e)
{
    while(s <= e)
    {
	int mid = (s + e) / 2;
	if(a[mid] == target)
	    return mid;
	if(a[s] <= a[mid])
	{
	    if(a[s] <= target && target < a[mid])
		e = mid-1;
	    else
		s = mid+1;
	}
	else
	{
	    if(a[mid] < target && target <= a[e])
		s = mid+1;
	    else
		e = mid-1;
	}
    }
    return -1;
}

int main()
{
    int s[] = {4, 5, 6, 7, 8, 1, 2, 3};
    for(int i = 0; i < 8; ++i)
	cout << s[i] << " ";
    cout << endl;
    cout << "Find 5 in index : " << findIndex(s, 5, 0, 7) << endl;
    
    return 0;
}
	   
