#include<stdio.h>
#include<string.h>


int main(){
	char pat[100];
	char str[100];
	printf("Enter string:\n");
	scanf("%s",str);
	printf("Enter pattern:\n");
	scanf("%s",pat);
	int m = strlen(pat);
	int n = strlen(str);
	int flag=0;
	for(int s=0;s<=n-m;i++)
	{
		if(str[s] == pat[0])
		{
			flag=0;
			for(int i=0;i<m;i++)
			{
				if(str[s+i] != pat[i])
					flag=1;
			}
		}
		if(flag==0)
		{
			printf("%d ",s);
		}
	}
	printf("\n");
	return 0;
}                   

