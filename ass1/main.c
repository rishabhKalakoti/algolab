#include<stdio.h>
#include "dec.h"

int main()
{
	int arr[MAX];
	initArray(arr,MAX,LENGTH);
    int arr1[MAX];

	copyArray(arr,arr1,MAX);
	bubble(arr1, MAX);

	copyArray(arr,arr1,MAX);
	insert(arr1,MAX);

	copyArray(arr,arr1,MAX);
	select(arr1,MAX);

	copyArray(arr,arr1,MAX);	
	mergeSort(arr1, 0, MAX-1);

	copyArray(arr,arr1,MAX);	
	quick(arr1, 0, MAX-1);

    printArray(arr1, MAX);
	return 0;
}
