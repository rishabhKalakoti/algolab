void merge(int *arr, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 =  r - q;
 	int i, j, k;
    int L[n1], M[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];
    i = 0; 
    j = 0; 
    k = p; 
	while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int p, int r)
{
    if (p >= r) 
        return;
    int q=(p+r)/2;
    mergeSort(arr, p, q);
    mergeSort(arr, q+1, r);
    merge(arr, p, q, r);
}
