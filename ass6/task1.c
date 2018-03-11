
int max(int a,int b){
	if(a>b)
		return a;
	return b;
}
#include<stdio.h>
int main(){
	int n,i,j,w;
	printf("Enter n\n");
	scanf("%d",&n);
	int weight[n];
	int value[n];
	printf("Enter weight array\n");
	for(i=0;i<n;i++){
		scanf("%d",&weight[i]);
	}
	printf("Enter Value array\n");
	for(i=0;i<n;i++)
		scanf("%d",&value[i]);
	printf("Enter max Weight\n");
	scanf("%d",&w);
	//dp
	int dp[n+1][w+1];
	for(i=0;i<=n;i++){
		for(j=0;j<=w;j++){
			if(i==0 || j==0)
				dp[i][j]=0;
			else if(weight[i-1]<=j)
				dp[i][j] = max(value[i-1] + dp[i-1][j - weight[i-1]], dp[i-1][j]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	
	printf("Using Dynamic Programming Approach : %d\n",dp[n][w]); 
	
	//greedy
	float arr[n];
	for(i =0;i<n;i++){
		arr[i] = (float)value[i]/weight[i];
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				
				temp = value[i];
				value[i]=value[j];
				value[j]=temp;
				
				temp = weight[i];
				weight[i] = weight[j];
				weight[j]=temp;
			}
		}
	}
	int curr = 0;
	float ans = 0.0;
	
	for(i=n-1;i>=0;i--){
		if(curr + weight[i]<=w){
			curr += weight[i];
			ans += value[i]; 
			printf("Weight: %d\n",weight[i]);
		}
		else{
			int remain = w - curr;
            		ans += value[i] * ((float) remain /weight[i]);
			printf("Fractional part of weight : %d\n",weight[i]);
            		break;
		}
	
	}
	
	printf("Answer Using Greedy Approach : %f\n",ans);
	
	
}
