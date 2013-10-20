#include <iostream>
#include <string>
using namespace std;

string replace(string s, int len)
{
    int j = s.size()-1;
    for(int i = len-1; i >= 0; --i)
    {
	if(s[i] == ' ')
	{
	    s[j] = '0';
	    s[j-1] = '2';
	    s[j-2] = '%';
	    j = j-3;
	}
	else
	{
	    s[j] = s[i];
	    --j;
	}
    }
    return s;
}

int main()
{
    string s1("a b c    ");
    string s2("My name is  what?           ");
    cout << s1 << " -> " << replace(s1, 5) << endl;
    cout << s2 << " -> " << replace(s2, 18) << endl;
    return 0;
}
