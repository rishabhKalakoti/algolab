#include<stdio.h>

int main()
{
	int V,l;
	scanf("%d",&V);
	scanf("%d",&l);
	int i;
	int edges[l][2];
	for(i=0;i<l;i++)
	{
		scanf("%d %d",&edges[i][0],&edges[i][1]);
	}
	return 0;
}