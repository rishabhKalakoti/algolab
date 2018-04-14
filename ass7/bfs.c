#include<stdio.h>
 
void BFS(int);
int G[1000][1000],visited[100],n;
int pre[1000];
int c=1;
void main()
{
    int i,j;
 	// vertices
    scanf("%d",&n);
    int a,b;
    while(scanf("%d %d",&a,&b)>0)
    	G[a][b]=1;
    for(i=0;i<n;i++)
        visited[i]=0;
 	// 0-white
 	for(i=0;i<n;i++)
 	{
 		if(!visited[i])
 		{
 			pre[i]=-1;
 			BFS(i);
 			printf("\n");
 		}
 	}
 	printf("Vertex:\tPre:\t\n");
	for(i=0;i<n;i++)
	{
		printf("%5d\t%5d\n",i,pre[i]);
	}
}
 
void BFS(int i)
{
    int j;
	visited[i]=1;
    // 1-grey
	int Q[1000];
	int qPtr=-1;
	Q[++qPtr]=i;
	while(qPtr>=0)
	{
		int v=Q[0];
		printf("%d\n",v);
		for(j=0;j<qPtr;j++)
			Q[j]=Q[j+1];
		qPtr--;
		for(j=0;j<n;j++)
	    	if(!visited[j] && G[v][j]==1)
			{
				pre[j]=v;
				Q[++qPtr]=j;
				// 1-grey
				visited[j]=1;
			}
		// 2-black
		visited[i]=2;
	}
}
