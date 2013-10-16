#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int> > &M, int N)
{
    for(int i = 0; i < N/2; ++i)
    {
	for(int j = i; j < N-i-1; ++j)
	{
	    int tmp = M[i][j];
	    M[i][j] = M[N-1-j][i];
	    M[N-1-j][i] = M[N-1-i][N-1-j];
	    M[N-1-i][N-1-j] = M[j][N-1-i];
	    M[j][N-1-i] = tmp;
	}
    }
}

int main()
{
    int N = 4;
    vector<vector<int> > M(N, vector<int>(N, 0));
    for(int i = 0; i < N; ++i)
    {
	for(int j = 0; j < N; ++j)
	{
	    M[i][j] = i*N+j;
	    cout << M[i][j] << " ";
	}
	cout << endl;
    }
    rotate(M, N);
    for(int i = 0; i < N; ++i)
    {
	for(int j = 0; j < N; ++j)
	{
	    cout << M[i][j] << " ";
	}
	cout << endl;
    }
    return 0;
}
