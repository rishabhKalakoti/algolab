#include<stdio.h>
#define N 8
#define ll long long int
ll mat[N][N];
ll max,min;
ll maxN(ll a,ll b){if(a>b)return a; return b;}
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
	for(i=0;i<N;i++)
	{
		if(mat[i][k]>max) max=mat[i][k];
	}
	if(max>1)
		return 1;
	return 0;
}

void printMatrix()
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			printf("%lld ",mat[i][j]);
		printf("\n");
	}

}

int main()
{
	ll i,j;
	// input
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			scanf("%lld",&mat[i][j]);
	int flag[N]={0};
	// process
	int f=0;
	for(i=0;i<N;i++)
	{
		f=0;
		if(flag[i]==0 && rt(i)==0 )
		{
			op('s',i,1);
			flag[i]=1;
		}
		if(flag[i]!=1)
		{
			rt(i);
			min=max;
			for(j=0; j<N;j++)
			{
				while((mat[j][i]*2) <= max)
				{
					op('d',j,0);
				}
				if(mat[j][i] < min)
					min = mat[j][i];
			}
			op('s',i,min-1);
		}
		if(i==(N-1))
			i=-1;
		
		for(j=0;j<N;j++)
			if(flag[j]==0)
				f=1;
		if(f!=1)
			break;
		// printMatrix();
	}
	
	printf("\nFinal matrix:\n");
	printMatrix();
	
	return 0;
}
