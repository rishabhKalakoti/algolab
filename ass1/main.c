#include<stdio.h>
#include "dec.h"

int main()
{
	int arr[MAX];
	initArray(arr,MAX,1000);
    bubble(arr, MAX);
    printArray(arr, MAX);
	return 0;
}
