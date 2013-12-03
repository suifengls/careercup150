#include "../careercup.h"
using namespace std;

int findIndex(int a[], int target, int &i, int &j, int m, int n)
{
    while(i < m && j >= 0)
    {
	if(a[i*n+j] == target)
	    return 1;
	else if(a[i*n+j] < target)
	    ++i;
	else
	    --j;
    }
    return -1;    
}

int main()
{
    int s[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    for(int i = 0; i < 3; ++i)
    {
	for(int j = 0; j < 4; ++j)
	    cout << s[i*3+j] << " ";
	cout << endl;
    }
    int i = 0, j = 3;
    int find = findIndex(s, 5, i, j, 3, 4);
    if(find == 1)
	cout << "Find 5 at (" << i << ", " << j << ")" << endl;
    else
	cout << "Not Found" << endl;
    return 0;
}
	   
