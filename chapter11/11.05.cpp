#include "../careercup.h"
using namespace std;

int findIndex(string str[], string target, int s, int e)
{
    if(target == "")
	return -1;
    while(s <= e)
    {
	int mid = (s + e) / 2;
	int t = mid;
	while(str[t] == "" && t <= e)
	    ++t;
	if(t > e)
	    e = mid - 1;
	else
	{
	    if(str[t] == target)
		return t;
	    else if(str[t] <= target)
		s = t + 1;
	    else
		e = mid-1;
	}
    }
    return -1;
}

int main()
{
    string s[] = {"ab", "", "", "abc", "", "", "", "ss", "", "", "wz", ""};
    for(int i = 0; i < 12; ++i)
	cout << s[i] << " ";
    cout << endl;
    cout << "Find abc in index : " << findIndex(s, "wz", 0, 11) << endl;
    
    return 0;
}
	   
