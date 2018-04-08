#include<stdio.h>
 
void DFS(int);
int G[1000][1000],visited[100],n;
 
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
 			DFS(i);
 			printf("\n");
 		}
 	}
}
 
void DFS(int i)
{
    int j;
    printf("%d\n",i);
    // 1-grey
    visited[i]=1;
    
    for(j=0;j<n;j++)
       if(!visited[j] && G[i][j]==1)
            DFS(j);
    // 2-black
    visited[i]=2;
}
