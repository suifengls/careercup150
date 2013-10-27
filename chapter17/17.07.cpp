#include "../careercup.h"
using namespace std;

string digits[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
string teens[] = {"", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string tens[] = {"", "Ten ", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};

string convert(int n)
{
    string s("");
    if(n >= 100)
    {
	s += digits[n/100] + " Hundred ";
	n %= 100;
    }
    if(n >= 10)
    {
	if(n < 20)
	{
	    s += teens[n];
	    return s;
	}
	else
	{
	    s += tens[n/10];
	    n %= 10;
	}
    }
    s += digits[n];
    return s;
}

string phrase(int n)
{
    if(n == 0)
	return "Zero";
    string s("");
    if(n < 0)
    {
	s += "Negative ";
	s += phrase(-n);
    }
    if(n > 1000000)
    {
	s += convert(n/1000000) + " Million ";
	n %= 1000000;
    }
    if(n > 1000)
    {
	s += convert(n/1000) + " Thousand ";
	n %= 1000;
    }
    if(n > 0)
	s += convert(n);
    return s;
}	     

int main()
{
    int a = 101;
    int b = -123;
    int n = 123456789;
    cout << a << " -> " << phrase(a) << endl;
    cout << b << " -> " << phrase(b) << endl;
    cout << n << " -> " << phrase(n) << endl;

    return 0;
}
