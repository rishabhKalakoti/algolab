#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	int V;
	printf("Enter V (V>=3):\t");
	scanf("%d",&V);
	int edges[V][2];
	int i;
	int a,b;
	srand(time(0));
	int j=0,k;
	int l;
	do{
		l=rand()%((V*(V-1))/2);
	}while(!(l>0));
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
			if(a==edges[k][0] && b==edges[k][1])
				flag=1;
		}
		if(flag==0)
		{
			edges[i][0]=a;
			edges[i][1]=b;
			i++;
		}
	}
	int n=i;
	printf("Random edges generated:\n");
	for(i=0;i<n;i++)
		printf("(%d,%d)\n", edges[i][0],edges[i][1]);
		
	
	//arr[i]=rand()%V;
	return 1;
}
