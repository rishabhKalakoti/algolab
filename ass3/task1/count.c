#include<stdio.h>
#include<sys/time.h>
#include<string.h>
int main()
{
	char s[200];
	scanf("%s", s);
	// algo 1
	int length=strlen(s);
	long time_start, time_end;
	struct timeval tv;
	gettimeofday(&tv,NULL); /*gets the current system time into variable tv */
	time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
	int i;
	int cX=0,count=0;
	for(i=0;i<length;i++)
		if(s[i]=='X')
			cX++;
		else if(s[i]=='Y')
			count+=cX;
	gettimeofday (&tv, NULL);
	time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
	printf("---------------\n");
	printf("Algo 1\n");
	printf("---------------\n");
	printf("Answer: %d\n",count);
	printf("Complexity = O(n)\n");
	printf("Running Time = %ld micro sec\n",time_end-time_start);
	int j;
	count=0;
	for(i=0;i<length;i++)
		if(s[i]=='X')
			for(j=i+1;j<length;j++)
				if(s[j]=='Y')
					count++;
	time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
	printf("---------------\n");
	printf("Algo 2\n");
	printf("---------------\n");
	printf("Answer: %d\n",count);
	printf("Complexity = O(n2)\n");
	printf("Running Time = %ld micro sec\n",time_end-time_start);

	time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
	return 0;
}
