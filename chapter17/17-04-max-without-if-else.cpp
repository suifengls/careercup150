#include "../careercup.h"
using namespace std;

int findMax(int a, int b)
{
    int c = a - b;
    int d = (c >> 31) & 1;
    return a - d * c;
}

int main()
{
    int a = 5;
    int b = 2;
    cout <<  findMax(a, b) << endl;

    return 0;
}
