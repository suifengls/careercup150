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

// some problems
int robotPath2(int x, int y, vector<vector<int> > &P)
{
    bool obx = false, oby = false;
    vector<int> paths(x+1, 0);
 
    for(int i = 1; i <= x; ++i)
    {
	if(obx)
	    paths[i] = 0;
	else
	{
	    if(P[0][i-1] == 0)
		paths[i] = 1;
	    else
	    {
		paths[i] = 0;
		obx = true;
	    }
	}
    }
	   
    for(int i = 2; i <= y; ++i)
    {
	if(oby)
	    paths[0] = 0;
	else if(P[i-1][0] == 1)
	{
	    paths[0] = 0;
	    oby = true;
	}
	else
	    paths[0] = 1;
	for(int j = 1; j <= x; ++j)
	{
	    if(P[i-1][j-1] == 1)
		paths[j] = 0;
	    else
		paths[j] += paths[j-1];
	}
    }
    return paths[x];
}

int main()
{
    vector<vector<int> > P(3, vector<int>(4, 0));
    for(int i = 0; i < 3; ++i)
    {
	for(int j = 0; j < 4; ++j)
	    cout << P[i][j] << " ";
	cout << endl;
    }
    cout << "(0, 0) -> (3, 4)" << endl;
    cout << robotPath(3, 4) << endl;
    cout << robotPath2(3, 4, P) << endl;
    
    return 0;
}
