#include <sys/time.h>
#include<stdio.h>
int arr[500];
int st[500];
int length;
int maxSize=0;
int maxSub[500];
void maxSeq(int c,int stPtr)
{
	if(c==length)
	{
		if(stPtr>maxSize)
		{
			int j;
			maxSize=stPtr;
			for(j=0; j<maxSize;j++)
			{
				maxSub[j]=st[j];
			}
		}
	}
	else
	{
		maxSeq(c+1,stPtr);
		if(stPtr==0)
		{
			st[stPtr]=arr[c];
			maxSeq(c+1,stPtr+1);
		}
		else
		{
		
			if(arr[c]>st[stPtr-1])
			{
				st[stPtr]=arr[c];
				maxSeq(c+1,stPtr+1);
			}
		}
	}
}

int main()
{
	
	int x;
	int i=0;
	long time_start, time_end;
	struct timeval tv;
	gettimeofday(&tv,NULL);
	time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
	
	
	while(scanf("%d",&x)>0)
	{
		arr[i]=x;
		//printf("%d ",arr[i]);
		i++;
	}
	//printf("\n");
	length=i;
	maxSeq(0,0);
	printf("size = %d\n",maxSize);
	for(i=0; i<maxSize;i++)
	{
		printf("%d ",maxSub[i]);
	}
	printf("\n");
	gettimeofday (&tv, NULL);
	time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
	printf("Time:\t %ldms\n",time_end - time_start);	
	return 0;
}
