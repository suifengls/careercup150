#include "../careercup.h"
using namespace std;

void printReal(double n)
{
    vector<int> m;
    int i = 0;
    while(i < 32 && n > 0.0)
    {
	n *= 2;
	if(n >= 1.0)
	{
	    n -= 1.0;
	    m.push_back(1);
	}
	else
	    m.push_back(0);
	++i;
    }
    if(i == 32 && n > 0.0)
	cout << "ERROR." << endl;
    else
    {
	cout << "0.";
	for(i = 0; i < m.size(); ++i)
	    cout << m[i];
	cout << endl;
    }
}

int main()
{
    cout << "0.1 -> ";
    printReal(0.1);
    cout << "0.25 -> ";
    printReal(0.25);
    cout << "0.5 -> ";
    printReal(0.5);
    cout << "0.8 -> ";
    printReal(0.8);
    return 0;
}
