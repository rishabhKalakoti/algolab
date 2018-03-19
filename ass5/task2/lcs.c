#include<stdio.h>
#include<string.h>
#define MAXN 100
int max(int a, int b){if(a>b) return a; return b;}
int solve(char* s1, char* s2)
{
	int m = strlen(s1);
	int n = strlen(s2);
	int dp[m+1][n+1];
	int s[m+1][n+1];
	int i,j;
	for (i=0; i<=m; i++)
	{
		for (j=0; j<=n; j++)
		{
   			if (i == 0 || j == 0)
	       	{
	       	 		dp[i][j] = 0;
	       	 		s[i][j]=0;
	       	}		
	    		else if (s1[i-1] == s2[j-1])
	    		{
	        		dp[i][j] = dp[i-1][j-1] + 1;
	        		s[i][j]=3;
	        	}
	    		else
	    		{
	        		dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	        		if(dp[i][j]==dp[i-1][j])
	        			s[i][j]=1;
	        		else if(dp[i][j]==dp[i][j-1])
	        			s[i][j]=2;
	        	}
			
		}	
	}
	i=m; j=n;
	while(s[i][j]!=0)
	{
		if(s[i][j]==3)
		{
			printf("%c<-",s1[i-1]);
			i--;
			j--;
		}
		else if(s[i][j]==2)
		{
			j--;
		}
		else if(s[i][j]==1)
		{
			i--;
		}
	}
	printf("\n");
	return dp[m][n];
}

int main()
{
	char s1[MAXN],s2[MAXN];
	scanf("%s",s1);
	scanf("%s",s2);
	printf("LCS length: %d\n",solve(s1,s2));
	return 0;
}
