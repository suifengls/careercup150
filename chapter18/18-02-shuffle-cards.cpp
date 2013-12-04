void RandomShift(int a[], int n)
{
    for(int i = 0; i < n; ++i)
    {
	int j = rand() % (n-i) + i;
	swap(a[i], a[j]);
    }
}
