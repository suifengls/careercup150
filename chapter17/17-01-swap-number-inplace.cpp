#include "../careercup.h"
using namespace std;

void swap1(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void swap2(int &a, int &b)
{
    b = a - b;
    a = a - b;
    b = a + b;
}

int main()
{
    int a = 5;
    int b = 2;
    cout << a << " and " << b << endl;
    swap1(a, b);
    cout << a << " and " << b << endl;
    swap2(a,b);
    cout << a << " and " << b << endl;

    return 0;
}
