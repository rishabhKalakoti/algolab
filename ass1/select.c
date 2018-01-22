void selectSort(int *p, int size)
{
	int i,j,minX,temp;
	for (i=0; i<size-1; i++)
	{
		minX=i;
		for(j=i+1; j<size; j++)
		if(p[j] < p[minX])
			minX = j;
		temp=p[minX];
		p[minX]=p[i];
		p[i]=temp;
	}
}
