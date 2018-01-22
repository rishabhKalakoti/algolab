void bubble(int* p, int size)
{
	int i,j,temp;
	for(i=0; i<size; i++)
	{
		for(j=0; j<size-1-i;j++)
		{
			if(p[j]>p[j+1])
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
}
