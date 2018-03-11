#include<string.h>
int max(int, int);
int solve(char* s1, char* s2, char* s3)
{
	int m = strlen(s1);
	int n = strlen(s2);
	int o = strlen(s3);
	int dp[m+1][n+1][o+1];
	int i,j,k;
	for (i=0; i<=m; i++)
	{
		for (j=0; j<=n; j++)
		{
	   		for (k=0; k<=o; k++)
	   		{
		    		if (i == 0 || j == 0|| k==0)
		       	 		dp[i][j][k] = 0;
		    		else if ((s1[i-1] == s2[j-1]) && (s1[i-1]==s3[k-1]))
		        		dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
		    		else
		        		dp[i][j][k] = max(max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);
			}
		}	
	}
	return dp[m][n][o];
}

