void Random(int a[], int n, int m)
{
    for(int i = 0; i < m; ++i)
    {
	int j = rand() % (n-i) + i;
	swap(a[i], a[j]);
    }
}
