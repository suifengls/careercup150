#include <iostream>
#include <vector>
using namespace std;

void Zeros(vector<vector<int> > &Mat, int M, int N)
{
    vector<int> row(M, 0);
    vector<int> col(N, 0);
    for(int i = 0; i < M; ++i)
	for(int j = 0; j < N; ++j)
	    if(Mat[i][j] == 0)
	    {
		row[i] = 1;
		col[j] = 1;
	    }
    for(int i = 0; i < M; ++i)
    {
	if(row[i])
	{
	    for(int j = 0; j < N; ++j)
		Mat[i][j] = 0;
	}
    }
    for(int j = 0; j < N; ++j)
    {
	if(col[j])
	{
	    for(int i = 0; i < M; ++i)
		Mat[i][j] = 0;
	}
    }
    return;
}

int main()
{
    int M = 4;
    int N = 5;
    vector<vector<int> > Mat(M, vector<int>(N, 1));
    Mat[0][0] = 0;
    Mat[3][2] = 0;
    Mat[3][3] = 0;
    for(int i = 0; i < M; ++i)
    {
	for(int j = 0; j < N; ++j)
	{
	    cout << Mat[i][j] << " ";
	}
	cout << endl;
    }
    Zeros(Mat, M, N);
    cout << "Set zeros:" << endl;
    for(int i = 0; i < M; ++i)
    {
	for(int j = 0; j < N; ++j)
	{
	    cout << Mat[i][j] << " ";
	}
	cout << endl;
    }
    return 0;
}
