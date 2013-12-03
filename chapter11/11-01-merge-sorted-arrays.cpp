#include "../careercup.h"
using namespace std;

void merge(int a[], int m, int b[], int n)
{
    int k = m + n - 1;
    while(m > 0 && n > 0)
    {
	if(b[n-1] > a[m-1])
	{
	    a[k] = b[n-1];
	    --n;
	}
	else
	{
	    a[k] = a[m-1];
	    --m;
	}
	--k;
    }
    while(n > 0)
    {
	a[k] = b[n-1];
	--n;
	--k;
    }
}

int main()
{
    int a[10] = {1, 2, 3, 6, 9, 10, 13};
    int b[3] = {4, 7, 11};
    for(int i = 0; i < 10; ++i)
	cout << a[i] << " ";
    cout << endl;
    for(int i = 0; i < 3; ++i)
	cout << b[i] << " ";
    cout << endl;
    cout << "After merge" << endl;
    merge(a, 7, b, 3);
    for(int i = 0; i < 10; ++i)
	cout << a[i] << " ";
    cout << endl;

    return 0;
}
	   
