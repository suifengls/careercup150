int count2s(int n)
{
    int factor = 1;
    int count = 0;
    int low = 0, curr = 0, high = 0;

    while(n/factor != 0)
    {
	low = n % factor;
	curr = (n/factor) % 10;
	high = n/(10*factor);

	switch(curr)
	{
	case 0:
	case 1:
	    count += high * factor;
	    break;
	case 2:
	    count += hight * factor + low + 1;
	    break;
	default:
	    count += (high + 1) * factor;
	    break;
	}
	factor *= 10;
    }
    return count;
}
