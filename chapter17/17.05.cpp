#include "../careercup.h"
using namespace std;

void Guess(string s, string g)
{
    int hit = 0, phit = 0;
    vector<bool> hs(4, false);

    for(int i = 0; i < 4; ++i)
    {
	if(s[i] == g[i])
	{
	    ++hit;
	    hs[i] = true;
	    continue;
	}
	for(int j = 0; j < 4; ++j)
	{
	    if(i != j && !hs[j] && !hs[i] && s[i] == g[j])
		++phit;
	}
    }
    cout << hit << " hits." << endl;
    cout << phit << " pseudo-hits." << endl;
}

int main()
{
    Guess("RYGB", "YRRB");
    return 0;
}
