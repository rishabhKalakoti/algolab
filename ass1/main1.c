#include <sys/time.h>
#include <stdio.h>
#include "dec.h"
int main(int argc,char **argv)
{ 
	long time_start, time_end;
	struct timeval tv;
	int arr[MAX];
	initArray(arr,MAX,LENGTH);
	int arr1[MAX];

    	//printArray(arr1, MAX);
	
	int i;
	for(i=0;i<5;i++)
	{	
		copyArray(arr,arr1,MAX);
		gettimeofday(&tv,NULL); /*gets the current system time into variable tv */
		time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
		
		switch(i)
		{
			case 0:
				bubble(arr1, MAX);
				break;
			case 1:
				insert(arr1,MAX);
				break;
			case 2:
				selectSort(arr1,MAX);
				break;
			case 3:
				mergeSort(arr1, 0, MAX-1);
				break;
			case 4:
				quick(arr1, 0, MAX-1);
				break;
		}
		gettimeofday (&tv, NULL);
		time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
		printf("%d\t%ld\n",i+1,time_end-time_start);
	}
	// calculating end time in seconds //convert time in readable and printable precision
	// (time_end-time_start) gives the total execution time
	return 0;
}
