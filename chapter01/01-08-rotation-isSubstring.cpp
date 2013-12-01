#include <iostream>
#include <string>
using namespace std;

bool isSubstring(string s1, string s2)
{
    if(s1.find(s2) != string::npos)
	return true;
    return false;
}

bool isRotation(string s1, string s2)
{
    if(s1.size() != s2.size())
	return false;
    return isSubstring(s1+s1, s2);
}

int main()
{
    string s1("asdfghjkl");
    string s2("ghjklasdf");
    string s3("asdfghjlk");
    string s4("asdfghjl");

    cout << s1 << " is rotation of " << s2 << " ? " << isRotation(s1, s2) << endl;
    cout << s1 << " is rotation of " << s3 << " ? " << isRotation(s1, s3) << endl;
    cout << s1 << " is rotation of " << s4 << " ? " << isRotation(s1, s4) << endl;
    return 0;
}
