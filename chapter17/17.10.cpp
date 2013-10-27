#include "../careercup.h"
using namespace std;

void findsum(int a[], int n, int sum)
{
    int i = 0, j = n-1;
    sort(a, a+n);
    while(i < j)
    {
	int add = a[i] + a[j];
	if(add == sum)
	{
	    cout << a[i] << " and " << a[j] << endl;
	    ++i;
	    --j;
	}
	else if(add > sum)
	    --j;
	else
	    ++i;
    }
}

int main()
{
    int a[] = {1, 0, 4, 3, 2, 6, 5};
    findsum(a, 7, 5);

    return 0;
}
