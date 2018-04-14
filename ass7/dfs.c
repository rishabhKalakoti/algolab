#include<stdio.h>
 
void DFS(int);
int G[1000][1000],visited[1000],n;
int pre[1000],stime[1000],etime[1000];
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
			DFS(i);
			printf("\n");
		}
	}
	printf("Vertex:\tPre:\tStart:\tEnd:\t\n");
	for(i=0;i<n;i++)
	{
		printf("%5d\t%5d\t%5d\t%5d\n",i,pre[i],stime[i],etime[i]);
	}
}
 
void DFS(int i)
{
    int j;
    printf("%d\n",i);
    // 1-grey
    visited[i]=1;
    stime[i]=c++;
    for(j=0;j<n;j++)
    {
	   if(!visited[j] && G[i][j]==1)
		{
			pre[j]=i;
            DFS(j);
		}
    }
    // 2-black
    etime[i]=c++;
    visited[i]=2;
}
