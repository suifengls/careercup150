#include <iostream>
#include <string>
using namespace std;

string Compression(string s)
{
    if(s.size() == 0)
	return s;
    char prev = s[0];
    int count = 1;
    int i = 1;
    string cs("");
    while(i < s.size())
    {
	if(s[i] == s[i-1])
	    ++count;
	else
	{
	    cs += prev;
	    cs += (count + '0');
	    prev = s[i];
	    count = 1;
	}
	++i;
    }
    cs += prev;
    cs += (count + '0');
    if(cs.size() >= s.size())
	return s;
    return cs;
}

int main()
{
    string s1("aaabb");
    string s2("ab");
    string s3("aabbccc");
    cout << s1 << " -> " << Compression(s1) << endl;
    cout << s2 << " -> " << Compression(s2) << endl;
    cout << s3 << " -> " << Compression(s3) << endl;
    return 0;
}
