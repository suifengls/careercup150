#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool isAnagram1(string a, string b)
{
    if(a.size() != b.size())
	return false;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if(a == b)
	return true;
    else
	return false;
}

bool isAnagram2(string a, string b)
{
    if(a.size() != b.size())
	return false;
    vector<int> count(256, 0);
    for(int i = 0; i < a.size(); ++i)
    {
	++count[a[i]];
	--count[b[i]];
    }
    for(int i = 0; i < 256; ++i)
    {
	if(count[i])
	    return false;
    }
    return true;
}

int main()
{
    string a1("asdfghjkl");
    string b1("lkjhgfdsa");
    string a2("qwertyuiop");
    string b2("poiuytrewd");
    cout << "Anagram1:" << endl;
    cout << a1 << " and " << b1 << " are anagrams? " << isAnagram1(a1, b1) << endl;
    cout << a2 << " and " << b2 << " are anagrams? " << isAnagram1(a2, b2) << endl;
    cout << "Anagram2:" << endl;
    cout << a1 << " and " << b1 << " are anagrams? " << isAnagram2(a1, b1) << endl;
    cout << a2 << " and " << b2 << " are anagrams? " << isAnagram2(a2, b2) << endl;
    return 0;
}
