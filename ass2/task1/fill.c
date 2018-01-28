#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>
#define llu long long unsigned int
#define ll long long int
llu min(llu a,llu b)
{
	if(a<b)
		return a;
	else
		return b;
}
int main(int argc, char** argv)
{
	if(argc!=3)
	{
		printf("Improper command line arguments.\n");
		return 1;
	}
	long time_start, time_end;
	struct timeval tv;
	gettimeofday(&tv,NULL); /*gets the current system time into variable tv */
	time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
	llu row=atoi(argv[1]);
	llu col=atoi(argv[2]);
	ll arr[row][col];
	llu i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			llu minX=min(i,min(j,min(row-1-i,col-1-j)));
			arr[i][j]=minX;
			printf("%llu ",minX);
		}
		printf("\n");
	}
	gettimeofday (&tv, NULL);
	time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
	printf("\nRunning complexity = c * no of elements\n");
	printf("Running complexity = c * row * col\n");
	printf("Running complexity = O(row*col)\n");
	printf("Running Time = %ld micro sec\n",time_end-time_start);
	return 0;
}
