#include "../careercup.h"
using namespace std;

int robotPath(int x, int y)
{
    vector<int> path(x+1, 1);
    for(int i = 1; i <= y; ++i)
    {
	path[0] = 1;
	for(int j = 1; j <= x; ++j)
	{
	    path[j] = path[j] + path[j-1];
	}
    }
    return path[x];
}

int main()
{
    cout << "(0, 0) -> (3, 4)" << endl;
    cout << robotPath(3, 4) << endl;
    
    return 0;
}
