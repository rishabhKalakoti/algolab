#include<stdio.h>
#include<string.h>
#define d 1000

void search(char pat[], char txt[], int q)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    // hash for pattern
    int p = 0;
    // hash for text
    int t = 0;
    int h = 1;
 
    // h = pow(d, M-1)%q
    for (i = 0; i < M-1; i++)
        h = (h*d)%q;
 
    for (i = 0; i < M; i++)
    {
        p = (d*p + pat[i])%q;
        t = (d*t + txt[i])%q;
    }
 
    for (i = 0; i <= N - M; i++)
    {
        if ( p == t )
        {
            for (j = 0; j < M; j++)
            {
                if (txt[i+j] != pat[j])
                    break;
            }
 
            if (j == M)
                printf("Pattern at shift %d \n", i);
        }
        if ( i < N-M )
        {
            t = (d*(t - txt[i]*h) + txt[i+M])%q;
 
            if (t < 0)
            t = (t + q);
        }
    }
}
 
int main()
{
    char txt[1000];
    char pat[100];
    scanf("%s",txt);
    scanf("%s",pat);
    int q = 101;
    search(pat, txt, q);
    return 0;
}
