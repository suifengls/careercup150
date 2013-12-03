#include "../careercup.h"
using namespace std;

void setHelper(vector<vector<int> > &result, vector<int> &sets, vector<int> &S, int k)
{
    result.push_back(sets);
    if(sets.size() == S.size())
	return;
    for(int i = k; i < S.size(); i++)
    {
	sets.push_back(S[i]);
	setHelper(result, sets, S, i+1);
	sets.pop_back();
    }
}

vector<vector<int> > subsets(vector<int> &S)
{
    vector<vector<int> > result;
    vector<int> sets;
    sort(S.begin(), S.end());
    setHelper(result, sets, S, 0);
    return result;
}

int main()
{
    vector<int> S;
    S.push_back(1);
    S.push_back(2);
    S.push_back(3);

    vector<vector<int> > subset = subsets(S);
    for(int i = 0; i < subset.size(); ++i)
    {
	cout << "[ ";
	for(int j = 0; j < subset[i].size(); ++j)
	    cout << subset[i][j] << " ";
	cout << "]" << endl;
    }
    return 0;
}
    
