#include "../careercup.h"
using namespace std;

int tailing(int n)
{
    int num = 0;
    while((n = n/5) > 0)
	num += n;
    return num;
}

int main()
{
    cout << "10! has tailing 0s: " << tailing(10) << endl;
    cout << "15! has tailing 0s: " << tailing(15) << endl;
    cout << "25! has tailing 0s: " << tailing(25) << endl;
    
    return 0;
}
