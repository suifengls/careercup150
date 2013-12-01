#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void reverse(char *str)
{
    int len = strlen(str); // strlen() return the lenght, exclude '\0'
    for(int i = 0; i < len/2; ++i)
    {
	char tmp = str[i];
	str[i] = str[len-1-i];
	str[len-1-i] = tmp;
    }
}

int main()
{
    char s1[] = "0123456789\0";
    char s2[] = "asdfghjkl\0";
    cout << s1 << " -> ";
    reverse(s1);
    cout << s1 << endl;
    cout << s2 << " -> ";
    reverse(s2);
    cout << s2 << endl;
    return 0;
}
    
