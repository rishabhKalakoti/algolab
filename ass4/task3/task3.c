#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	int V;
	printf("Enter V (V>=3):\t");
	scanf("%d",&V);
	int i;
	int a,b;
	srand(time(0));
	int j=0,k;
	int l;
	do{
		l=rand()%((V*(V-1))/2);
	}while(!(l>0));
	int edges[l][2];
	printf("%d\n",l);
	int flag;
	for(i=0; i<l;)
	{
		//srand(time(0));
		a=rand()%V;
		//srand(time(0));
		b=rand()%V;
		flag=0;
		if(a==b)
			flag=1;
		for(k=0;k<j;k++)
		{
			if((a==edges[k][0]) && (b==edges[k][1]))
				flag=1;
			if((b==edges[k][0]) && (a==edges[k][1]))
				flag=1;
		}
		if(flag==0)
		{
			edges[i][0]=a;
			edges[i][1]=b;
			i++;
		}
	}
	printf("Random edges generated:\n");
	for(i=0;i<l;i++)
		printf("(%d,%d)\n", edges[i][0],edges[i][1]);
	printf("\n");
	int visited[V];
	for(i=0;i<V;i++)
	{
		visited[i]=0;
	}
	int c=0;
	int stack[2*V];
	int stPtr=-1;
	for(i=0;i<l;i++)
	{
		j=edges[i][0];
		if(visited[j]==0)
		{
			c++;
			stack[++stPtr]=j;
			visited[j]=1;
			while(stPtr>=0)
			{
				j=stack[stPtr];
				stPtr--;
				printf("(%d)\n",j);
				for(k=0;k<l;k++)
				{
					if((edges[k][0]==j) && (visited[edges[k][1]]==0))
					{
						stack[++stPtr]=edges[k][1];
						visited[edges[k][1]]=1;
					}
					if((edges[k][1]==j) && (visited[edges[k][0]]==0))
					{
						stack[++stPtr]=edges[k][0];
						visited[edges[k][0]]=1;
					}
				}
			}
		}
	}
	for(i=0;i<V;i++)
	{
		if(visited[i]==0)
			c++;
	}
	printf("Edges needed: %d\n", c-1);
	return 1;
}
