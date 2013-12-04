#include "../careercup.h"
using namespace std;

int sumMax(int a[], int n)
{
    int dp[n];
    dp[0] = a[0];
    int max = dp[0];
    for(int i = 1; i < n; ++i)
    {
	if(dp[i-1] + a[i] > a[i])
	    dp[i] = dp[i-1] + a[i];
	else
	    dp[i] = a[i];
	if(max < dp[i])
	    max = dp[i];
    }
    return max;
}

int main()
{
    int a[] = {-8, 3, -2, 4, -10};
    cout << sumMax(a, 5) << endl;
    
    return 0;
}
