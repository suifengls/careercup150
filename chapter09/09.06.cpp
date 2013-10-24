#include "../careercup.h"
using namespace std;

void parHelper(vector<string> &par, int l, int r, int n, string p)
{
    if(l > n)
	return;
    if(l == n && r == n)
	par.push_back(p);
    else
    {
	parHelper(par, l+1, r, n, p+"(");
	if(l > r)
	    parHelper(par, l, r+1, n, p+")");
    }
}

vector<string> parentheses(int n)
{
    vector<string> par;
    parHelper(par, 0, 0, n, "");
    return par;
}

int main()
{
    int n = 3;
    vector<string> par = parentheses(3);
    for(int i = 0; i < par.size(); ++i)
	cout << par[i] << endl;
    return 0;
}
