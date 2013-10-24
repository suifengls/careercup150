#include "../careercup.h"
using namespace std;

void fill(vector<vector<int> > &screen, int m, int n, int x, int y, int c)
{
    if(x < 0 || x >= n || y < 0 || y >= m || screen[x][y] == c)
       return;
    else
    {
	screen[x][y] = c;
	fill(screen, m, n, x-1, y, c);
	fill(screen, m, n, x+1, y, c);
	fill(screen, m, n, x, y-1, c);
	fill(screen, m, n, x, y+1, c);
    }
}

int main()
{
    int n = 5;
    int m = 5;
    vector<vector<int> > screen(m, vector<int>(n, 0));
    screen[2][0] = 1;
    screen[2][1] = 1;
    screen[1][2] = 1;
    screen[0][2] = 1;
    screen[m-2][n-1] = 1;
    screen[m-1][n-2] = 1;

    for(int i = 0; i < screen.size(); ++i)
    {
	for(int j = 0; j < screen[i].size(); ++j)
	    cout << screen[i][j] << " ";
	cout << endl;
    }
    cout << "After filling: " << endl;
    fill(screen, m, n, 2, 4, 1);
    for(int i = 0; i < screen.size(); ++i)
    {
	for(int j = 0; j < screen[i].size(); ++j)
	    cout << screen[i][j] << " ";
	cout << endl;
    }
    
    return 0;
}
