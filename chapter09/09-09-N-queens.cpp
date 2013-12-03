#include "../careercup.h"
using namespace std;

bool isValid(vector<int> pos, int row)
{
    for(int i = 0; i < row; ++i)
    {
	if(pos[i] == pos[row] || (row - i) == abs(pos[i] - pos[row]))
	    return false;
    }
    return true;
}

void qHelper(vector<vector<int> > &result, vector<int> &pos, int row, int n)
{
    if(row == n)
	result.push_back(pos);
    else
    {
	for(int col = 0; col < n; ++col)
	{
	    pos[row] = col;
	    if(isValid(pos, row))
		qHelper(result, pos, row+1, n);
	}
    }
}

vector<vector<int> > Queens(int n)
{
    vector<vector<int> > result;
    vector<int> pos(n, -1);
    qHelper(result, pos, 0, n);
    return result;
}

int main()
{
    int n = 8;
    vector<vector<int> > queens = Queens(n);
    for(int i = 0; i < queens.size(); ++i)
    {
	for(int j = 0; j < queens[i].size(); ++j)
	    cout << queens[i][j] << " ";
	cout << endl;
    }
    return 0;
}
