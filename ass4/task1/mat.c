#include<stdio.h>
#define N 8
#define ll long long int
ll mat[N][N];
ll max,min;
ll maxN(ll a,ll b){if(a>b)return a;else return b;}
void op(char c, ll k,ll it)
{
	ll i;
	if(c=='s')
	{
		printf("Decrement column %lld by %lld\n",k,it);
		for(i=0;i<N;i++)
			mat[i][k]=mat[i][k]-it;
	}
	if(c=='d')
	{
		printf("Double row %lld\n",k);
		for(i=0;i<N;i++)
			mat[k][i]=mat[k][i]*2;
	}
}

ll rt(ll k)
{
	ll i;
	max=1;
	min=mat[0][k];
	for(i=0;i<N;i++)
	{
		if(mat[i][k]>max) max=mat[i][k];
		if(mat[i][k]<min) min=mat[i][k];
	}
	if(max>1)
		return 1;
	return 0;
}

int main()
{
	ll i,j;
	// input
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			scanf("%lld",&mat[i][j]);

	// process
	for(i=0;i<N;i++)
	{
		while(rt(i)==1)
		{
			for(j=0; j<N;j++)
			{
				min=max;
				while((mat[j][i]*2) <= max)
				{
					op('d',j,0);
				}
				if(mat[j][i]<min)
					min=mat[j][i];
			}
			op('s',i,min-1);
		}
		op('s',i,1);
	}
	/*
	printf("\nFinal matrix:\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			printf("%lld ",mat[i][j]);
		printf("\n");
	}
	*/
	return 0;
}
