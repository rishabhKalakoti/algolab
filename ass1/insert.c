void insert(int* p, int size)
{
	int i, x, j;
	for(i=1; i < size; i++)
	{
		x=p[i];
		j=i-1;
		while(j>=0 && p[j]>x)
		{
			p[j+1]=p[j];
			j--;
		}
		p[j+1]=x;
	}
}

