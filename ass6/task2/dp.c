#include<string.h>
#include<stdio.h>
int max(int, int);
int solve(char* s1, char* s2, char* s3)
{
	int m = strlen(s1);
	int n = strlen(s2);
	int o = strlen(s3);
	int dp[m+1][n+1][o+1];
	int s[m+1][n+1][o+1];
	int i,j,k;
	for (i=0; i<=m; i++)
	{
		for (j=0; j<=n; j++)
		{
	   		for (k=0; k<=o; k++)
	   		{
		    		if (i == 0 || j == 0|| k==0)
		       	{
		       	 		dp[i][j][k] = 0;
		       	 		s[i][j][k]=0;
		       	}		
		    		else if ((s1[i-1] == s2[j-1]) && (s1[i-1]==s3[k-1]))
		    		{
		        		dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
		        		s[i][j][k]=4;
		        	}
		    		else
		    		{
		        		dp[i][j][k] = max(max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);
		        		if(dp[i][j][k]==dp[i-1][j][k])
		        			s[i][j][k]=1;
		        		else if(dp[i][j][k]==dp[i][j-1][k])
		        			s[i][j][k]=2;
		        		else if(dp[i][j][k]==dp[i][j][k-1])
		        			s[i][j][k]=3;
		        	}
			}
		}	
	}
	i=m; j=n; k=o;
	while(s[i][j][k]!=0)
	{
		if(s[i][j][k]==4)
		{
			printf("%c<-",s1[i-1]);
			i--;
			j--;
			k--;
		}
		else if(s[i][j][k]==3)
		{
			k--;
		}
		else if(s[i][j][k]==2)
		{
			j--;
		}
		else if(s[i][j][k]==1)
		{
			i--;
		}
	}
	printf("\n");
	return dp[m][n][o];
}

