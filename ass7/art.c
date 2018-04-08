#include<stdio.h>
int edge[1000][1000]={0};
int visited[1000];
int v;
int DFS(int i,int k)
{
	int c=0;
    int j;
    // 1-grey
    visited[k]=1;
    c++;
    for(j=0;j<v;j++)
       if(!visited[j] && edge[k][j]==1 && j!=i)
            c+=DFS(i,j);
    // 2-black
    visited[i]=2;
    return c;
}

void main()
{
	scanf("%d",&v);
	int a,b;
	while(scanf("%d %d",&a,&b)>0)
		edge[a][b]=1;
	int i,k,j;
	for(i=0; i<v;i++)
	{
		for(j=0;j<v;j++)
			visited[j]=0;
		if(i==0)
			k=1;
		else
			k=0;
		int c=DFS(i,k);
		if(c<v-1)
			printf("%d\n",i);
	}
}
