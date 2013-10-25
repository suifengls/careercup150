#include "../careercup.h"
using namespace std;

struct person
{
    int h, w;
};

bool cmp(person p1, person p2)
{
    if(p1.h == p2.h)
	return p1.w < p2.w;
    else
	return p1.h < p2.h;
}

int maxNum(vector<person> p)
{
    sort(p.begin(), p.end(), cmp);
    vector<int> num(p.size(), 0);
    num[0] = p[0].w;
    int k = 1;
    for(int i = 1; i < p.size(); ++i)
    {
	if(p[i].w < num[k-1])
	    num[k-1] = p[i].w;
	else
	{
	    num[k] = p[i].w;
	    ++k;
	}
    }
    return k;
}

int main()
{
    vector<person> p;
    person p1;
    p1.h = 5;
    p1.w = 4;
    p.push_back(p1);
    person p2;
    p2.h = 4;
    p2.w = 3;
    p.push_back(p2);
    person p3;
    p3.h = 3;
    p3.w = 5;
    p.push_back(p3);

    cout << maxNum(p) << endl;
    return 0;
}
    
