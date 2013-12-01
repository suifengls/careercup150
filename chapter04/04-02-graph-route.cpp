#include "../careercup.h"
using namespace std;

bool isRoute(int src, int dst, vector<vector<bool> > graph, vector<bool> visited)
{
    if(graph.empty())
	return false;
    int n = graph.size();
    queue<int> q;
    visited[src] = true;
    q.push(src);
    while(!q.empty())
    {
	int tmp = q.front();
	q.pop();
	if(tmp == dst)
	    return true;
	for(int i = 0; i < n; ++i)
	{
	    if(!visited[i] && graph[tmp][i])
	    {
		visited[i] = true;
		q.push(i);
	    }
	}
    }
    return false;
}

int main()
{
    vector<vector<bool> > graph(4, vector<bool>(4, false));
    vector<bool> visited(4, false);
    graph[0][2] = true;
    graph[1][0] = true;
    graph[2][1] = true;
    graph[3][2] = true;
    graph[3][3] = true;
    
    cout << "A route from 3 to 0? " << isRoute(3, 0, graph, visited) << endl;;
    cout << "A route from 0 to 3? " << isRoute(0, 3, graph, visited) << endl;;
    
    return 0;
}
