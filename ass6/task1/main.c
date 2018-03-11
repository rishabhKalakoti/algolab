#include<stdio.h>
#include"heads.h"
void main()
{
	int W, N, i, ans;
	scanf("%d %d", &N, &W);
	float val[N], wt[N];
	//input all weights
	for(i=0; i<N; i++)
		scanf("%f", &wt[i]);
	//input all values
	for(i=0; i<N; i++)
		scanf("%f", &val[i]);
	ans = dynKnap(W, wt, val, N);
	printf("The dynamic approach  gives %d as the answer.\n", ans);
	greedKnap(N, wt, val, W);
}
	
	
