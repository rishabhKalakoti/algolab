#include <stdio.h>
int V;
int min(int a,int b){if(a<b) return a; return b;} 

int visited[1000];
void DFS(int re[V][V],int s,int t,int pre[])
{
    int i;
    int j;
    visited[i]=1;
    for(j=0;j<n;j++)
    {
	   if(!visited[j] && re[i][j]>1)
		{
			pre[j]=i;
            DFS(j);
		}
    }
    visited[i]=2;
}
/*
int bfs(int re[V][V], int s, int t, int pre[])
{
    int visited[V];
    int i;
    for(i=0;i<V;i++)
    	visited[i]=0;
    int Q[1000];
    int ptr=-1;
    Q[++ptr]=s;
    visited[s] = 1;
    pre[s] = -1;
    while (ptr>-1)
    {
        int u=Q[ptr--];
        int v;
        for (v=0; v<V; v++)
            if (visited[v]==0 && re[u][v] > 0)
            {
                Q[++ptr]=v;
                pre[v] = u;
                visited[v] = 1;
            }
    }
    return (visited[t] == 1);
}
*/
int ff(int edges[V][V], int src, int des)
{
    int u, v,i;
    int res[V][V];  
    for(i=0;i<V;i++)
	visited[i]=0;
 
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
             res[u][v] = edges[u][v];
    int pre[V];
    int maxflow = 0;
    while (dfs(res, src, des, pre))
    {
        int flow = 100000;
        for (v=des; v!=src; v=pre[v])
        {
            u = pre[v];
            flow = min(flow, res[u][v]);
        }
        for (v=des; v != src; v=pre[v])
        {
            u = pre[v];
            res[u][v] -= flow;
            res[v][u] += flow;
        }
        maxflow += flow;
    } 
    return maxflow;
}
 
int main()
{
	scanf("%d",&V);
	int src,des;
	scanf("%d %d",&src,&des);
	int i,j;
	int edges[V][V];
	for(i=0;i<V;i++)
		for(j=0;j<V;j++)
			edges[i][j]=0;
	int a,b,c;
	while(scanf("%d %d %d",&a,&b,&c)>0)
		edges[a][b]=c;
    printf("Max flow: %d\n",ff(edges, src, des));
 
    return 0;
}
