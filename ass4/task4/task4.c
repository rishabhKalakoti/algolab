#include<stdio.h>
#include<sys/time.h>
int max(int a,int b){
	if(a>b) return a;
	return b;
}
int main(){
	int n;
	long time_start, time_end;
	struct timeval tv;
	int arr[1000];
	int ans=0,temp[1000],temp1;
	int i=0,j=0,num;
	while(scanf("%i",&num)>0)
	{
		//printf("%d\n",num);
		arr[i]=num;
		if(i==0)
			temp[i]==arr[i];
		else
			temp[i]=temp[i-1]+arr[i];
		i++;
	}
	n=i;
	gettimeofday (&tv, NULL);
	time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
	ans=arr[0];
	for(i=0;i<n;i++){
		ans=max(ans,arr[i]);
		for(j=i+1;j<n;j++)
			ans = max(ans,temp[j]-temp[i]);
	}
	printf("%d\n",ans);
	temp1=0;
	for(i=0;i<n;i++){
		temp1=0;
		for(j=i;j<n;j++)
		{
			temp1+=arr[j];
			if(i==j)
				
			else
			if(temp1==ans)
				printf("[%d,%d]\n",i,j);
			
		}
	}
	
	//for(i=0;i<n;i++)
	//	printf("%d\n",temp[i]);
	gettimeofday (&tv, NULL);
	time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
	printf("Time taken = %ld ms\n",time_end-time_start);
	
	return 0;
}
