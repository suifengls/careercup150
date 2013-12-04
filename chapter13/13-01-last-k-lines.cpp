#include "../careercup.h"
using namespace std;

void printLast(ifstream &fin, int k)
{
    string line[k];
    int lines = 0;
    string tmp;
    while(getline(fin, tmp))
    {
	line[lines%k] = tmp;
	++lines;
    }

    int start = lines > k? (lines%k) : 0;
    int size = min(k, lines);

    for(int i = 0; i < size; ++i)
	cout << line[(start+i)%k] << endl;
}

int main()
{
    ifstream fin("test.dat");
    int k = 4;
    printLast(fin, k);
    fin.close();
    return 0;
}
