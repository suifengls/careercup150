#include "../careercup.h"
using namespace std;

int change(int n, int sum, int c)
{
    int ways = 0;
    if(sum == n)
	return 1;
    else if(sum < n)
    {
	switch(c)
	{
	case 25:
	    ways += change(n, sum+25, 25);
	case 10:
	    ways += change(n, sum+10, 10);
	case 5:
	    ways += change(n, sum+5, 5);
	case 1:
	    ways += change(n, sum+1, 1);
	}
    }
    return ways;
}

int main()
{
    cout << change(10, 0, 25) << endl;;
    return 0;
}
