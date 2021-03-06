#include<stdio.h>
#include<string.h>
    int lps[1000];
void computeLPSArray(char *pat, int M, int *lps);
void LPS(char *pat, int M, int *lps)
{
    int len = 0;
 
    lps[0] = 0; 

    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

    LPS(pat, M, lps);
    int i = 0;  
    int j  = 0;  
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
 
        if (j == M)
        {
            printf("Found pattern at index %d \n", i-j);
            j = lps[j-1];
        }
 
        
        else if (i < N && pat[j] != txt[i])
        {
           
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
}
 


int main()
{
	
	char txt[1000];
	char pat[100];
	scanf("%s", txt);
	scanf("%s", pat);
	KMPSearch(pat, txt);
	printf("LPS: ");
	int i;
	for(i=0;i<strlen(pat);i++)
		printf("%d ",lps[i]);
    return 0;
}
