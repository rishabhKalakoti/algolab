#include<time.h>
#include<stdio.h>
int main()
{
	int V;
	int i;
	int a,b;
	srand(time(0));
	int j=0,k;
	int l;
	do
	{
	V=rand()%10;
	}while(V<5);
	printf("%d\n",V);
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
	
	for(i=0;i<l;i++)
		printf("%d %d\n", edges[i][0],edges[i][1]);
	return 0;
}
