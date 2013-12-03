#include "../careercup.h"
using namespace std;

bool cmp(string s1, string s2)
{
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 < s2;
}

int main()
{
    string s[] = {"abc", "xyz", "xzy", "zxy", "bca", "cab"};
    sort(s, s+7, cmp);
    for(int i = 0; i < 7; ++i)
	cout << s[i] << " ";
    cout << endl;

    return 0;
}
	   
