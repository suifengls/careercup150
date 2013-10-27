int Add1(int a, int b)
{
    if(b == 0)
	return a;
    int sum = a^b; // sum without carry
    int carry = (a&b) << 1; // carry
    a = sum;
    b = carry;
    return Add1(a, b);
}

int Add2(int a, int b)
{
    while(b != 0)
    {
	int sum = a^b;
	int carry = (a&b) << 1;
	a = sum;
	b = carry;
    }
    return a;
}
