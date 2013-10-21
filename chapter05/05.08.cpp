#include "../careercup.h"
using namespace std;

typedef char byte;

void printbit(int n)
{
    vector<int> v;
    int mask = 1;
    int len = 8;
    while(len--)
    {
	if(n & mask)
	    v.push_back(1);
	else
	    v.push_back(0);
	mask = mask << 1;
    }
    while(!v.empty())
    {
	cout << v.back();
	v.pop_back();
    }
}


void drawLine(byte screen[], int width, int x1, int x2, int y)
{
    int start_offset = x1 % 8;
    int start = x1 / 8;
    int end_offset = x2 % 8;
    int end = x2 / 8;
    byte start_mask = (byte) (0xFF >> start_offset);
    byte end_mask = (byte) ~(0xFF >> (end_offset+1));
    if(start_offset != 0)
	++start;
    if(end_offset != 7)
	--end;
    for(int i = start; i <= end; ++i)
	screen[(width/8)*y + i] = (byte) 0xFF;
    if(start == end)
    {
	screen[(width/8)*y + x1/8] |= (start_mask & end_mask);
    }
    else
    {
	if(start_offset != 0)
	    screen[(width/8)*y + start - 1] |= start_mask;
	if(end_offset != 7)
	    screen[(width/8)*y + end + 1] |= end_mask;
    }
}

int main()
{
    byte screen[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for(int i = 0; i < 3; ++i)
    {
	for(int j = 0; j < 4; ++j)
	    printbit(screen[i*4+j]);
	cout << endl;
    }
    cout << "Draw a line at (1, 3 to (1, 17):" << endl;
    drawLine(screen, 32, 3, 17, 1);
    for(int i = 0; i < 3; ++i)
    {
	for(int j = 0; j < 4; ++j)
	    printbit(screen[i*4+j]);
	cout << endl;
    }

    return 0;
}
