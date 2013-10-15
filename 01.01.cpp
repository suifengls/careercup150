#include <iostream>
#include <vector>
using namespace std;

bool isUnique1(string s)
{
    vector<bool> unique(256, false);
    for(int i = 0; i < s.size(); ++i)
    {
	if(unique[s[i]])
	    return false;
	unique[s[i]] = true;
    }
    return true;
}

bool isUnique2(string s)
{
    vector<int> unique(8, 0);
    for(int i = 0; i < s.size(); ++i)
    {
	int index = s[i]/32;
	int shift = s[i]%32;
	if(unique[index] & (1 << shift))
	    return false;
	unique[index] |= (1 << shift);
    }
    return true;
}

int main()
{
    string s1("tfcvhvjkb");
    string s2("asdfghjkl");
    cout << "isUnique1:" << endl;
    cout << s1 << " is unique? " << isUnique1(s1) << endl;
    cout << s2 << " is unique? " << isUnique1(s2) << endl;
    cout << "isUnique2:" << endl;
    cout << s1 << " is unique? " << isUnique1(s1) << endl;
    cout << s2 << " is unique? " << isUnique1(s2) << endl;
    return 0;
}
       
