#include "../careercup.h"
using namespace std;

enum Check{ROW, COLUMN, DIAGONAL, REDIAGONAL};

int CheckRowColumn(int board[], int n, Check check)
{
    int type = 0;
    for(int i = 0; i < n; ++i)
    {
	bool found = true;
	for(int j = 0; j < n; ++j)
	{
	    int k;
	    if(check == ROW)
		k = i * n + j;
	    else
		k = i + n * j;
	    if(j == 0)
		type = board[k];
	    else if(board[k] != type)
	    {
		found = false;
		break;
	    }
	}
	if(found)
	    return type;
    }
    return 0;
}

int CheckDiagonal(int board[], int n, Check check)
{
    int type = 0;
    bool found = true;
    int k;
    for(int i = 0; i < n; ++i)
    {
	if(check == DIAGONAL)
	    k = i * n + i;
	else
	    k = i + n * (n-1-i);
	if(i == 0)
	    type = board[k];
	else if(board[k] != type)
	{
	    found = false;
	    break;
	}
    }
    if(found)
	return type;
    return 0;
}

int HasWon(int board[], int n)
{
    int type = 0;
    type = CheckRowColumn(board, n, ROW);
    if(type)
	return type;
    type = CheckRowColumn(board, n, COLUMN);
    if(type)
	return type;
    type = CheckDiagonal(board, n, DIAGONAL);
    if(type)
	return type;
    type = CheckDiagonal(board, n, REDIAGONAL);
    if(type)
	return type;
    return 0;
}
    

int main()
{
    int n = 3;
    int board[] = {1, 1, 2, 0, 1, 2, 2, 0, 2};
    cout << "Winner: " << HasWon(board, n) << endl;

    return 0;
}
