#include "../careercup.h"
using namespace std;

void permHelper(vector<string> &perm, string &s, int k)
{
    if(k == s.size())
	perm.push_back(s);
    else
    {
	for(int i = k; i < s.size(); ++i)
	{
	    swap(s[i], s[k]);
	    permHelper(perm, s, k+1);
	    swap(s[k], s[i]);
	}
    }
}

vector<string> permutations(string s)
{
    vector<string> perm;
    permHelper(perm, s, 0);
    return perm;
}

int main()
{
    string s("abc");
    vector<string> perm = permutations(s);
    for(int i = 0; i < perm.size(); ++i)
	cout << perm[i] << endl;
    return 0;
}
