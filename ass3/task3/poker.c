#include <sys/time.h>
#include<stdio.h>
char Black[5][2];
char White[5][2];

int max(int a,int b){(a>b)?a:b;}
int min(int a,int b){(a<b)?a:b;}

int value(char c)
{
	if(c>='2' && c<='9')
		return c-'0';
	switch(c)
	{
		case 'T':
			return 10;
		case 'J':
			return 11;
		case 'Q':
			return 12;
		case 'K':
			return 13;
		case 'A':
			return 14;
	}
	return 0;
}


void bubble_sp(char p[][2], int size)
{
	int i,j;
	char temp;
	for(i=0; i<size; i++)
	{
		for(j=0; j<size-1-i;j++)
		{
			if(value(p[j][1])>value(p[j+1][1]))
			{
				temp=p[j][1];
				p[j][1]=p[j+1][1];
				p[j+1][1]=temp;
				temp=p[j][0];
				p[j][0]=p[j+1][0];
				p[j+1][0]=temp;
			}
		}
	}
}

int input()
{
	int i=0;
	char x;
	while((x=fgetc(stdin))!=EOF)
	{
		if(x==0)
			return 0;
		if((x>='0' && x<='9') || (x>='A' && x<='Z'))
		{
			if(i<5)
			{
				Black[i][1]=x;
				scanf("%c",&x);
				Black[i][0]=x;
			}
			else if(i>=5 && i<10)
			{
				White[i-5][1]=x;
				scanf("%c",&x);
				White[i-5][0]=x;
			}
			i++;
			if(i>=10)
			{
				return 1;
			}
		}
	}
	return 0;
}

int process(char cards[][2])
{
	int i;
	// straight flush - 8
	bubble_sp(cards,5);
	int flag=0;
	int ival=80000;
	for(i=1;i<5;i++)
	{
		if(cards[i][0]!=cards[i-1][0])
			flag=1;
		if(value(cards[i][1])!=value(cards[i-1][1])+1)
			flag=1;
	}
	ival+=value(cards[4][1]);
	if(flag==0)
	{
		return ival;
	}
	// four of a kind - 7
	flag=0;
	ival=70000;
	if(cards[0][1]==cards[3][1] || cards[1][1]==cards[4][1])
	{
		flag=1;
		ival+=value(cards[2][1]);
	}
	if(flag==1)
	{
		return ival;
	}
	// full house - 6
	flag=0;
	ival=60000;
	if(cards[0][1]==cards[2][1] && cards[3][1]==cards[4][1])
	{
		flag=1;
		ival+=value(cards[0][1]);
	}
	if(cards[0][1]==cards[1][1] && cards[2][1]==cards[4][1])
	{
		flag=1;
		ival+=value(cards[2][1]);
	}
	if(flag==1)
	{
		return ival;
	}
	// flush - 5
	flag=0;
	ival=50000;
	for(i=1;i<5;i++)
	{
		if(cards[i][0]!=cards[i-1][0])
			flag=1;
	}
	ival=ival-15*15*value(cards[0][1]);
	ival=ival-15*value(cards[1][1]);
	ival=ival+1*value(cards[2][1]);
	ival=ival+15*value(cards[3][1]);
	ival=ival+15*15*value(cards[4][1]);
	if(flag==0)
	{
		return ival;
	}
	// straight - 4
	flag=0;
	ival=40000;
	for(i=1;i<5;i++)
	{
		if(value(cards[i][1])!=(value(cards[i-1][1])+1))
			flag=1;
	}
	ival+=value(cards[4][1]);
	if(flag==0)
		return ival;
	// three of a kind - 3
	flag=0;
	ival=30000;
	if(cards[0][1]==cards[2][1])
		return (ival+value(cards[0][1]));
	if(cards[1][1]==cards[3][1])
		return (ival+value(cards[1][1]));
	if(cards[2][1]==cards[4][1])
		return (ival+value(cards[2][1]));
	// two pairs - 2
	ival=20000;
	int num=0;
	int a=0,b=0;
	for(i=0;i<4;i++)
	{
		if(cards[i][1]==cards[i+1][0])
		{
			a=value(cards[i][1]);
			i+=2;
			break;
		}
		else
		{
			num=value(cards[i][1]);
		}
	}
	for(;i<4;i++)
	{
		if(cards[i][1]==cards[i+1][0])
		{
			b=value(cards[i][1]);
			i+=2;
			break;
		}
		else
		{
			num=value(cards[i][1]);
		}
	}
	if(num==0)
		num=value(cards[i][1]);
	if(a!=0 && b!=0)
	{
		ival=ival+max(a,b)*15;
		ival=ival+min(a,b);
		ival=ival-num;
		return ival;
	}
	// pair - 1
	ival=10000;
	a=-1,b=-1;
	num=0;
	for(i=0;i<4;i++)
	{
		if(cards[i][1]==cards[i+1][1])
		{
			a=i;
			b=i+1;
			num=value(cards[i][1]);
		}
	}
	ival=ival+15*num;
	int j=0;
	for(i=5;i>=0;i--)
	{
		if(i==a || i==b)
			continue;
		if(j==0)
		{
			ival+=value(cards[i][1]);
			j++;
		}
		else if(j==1)
		{
			ival-=value(cards[i][1]);
			j++;
		}
		else
		{
			ival=ival-15*value(cards[i][1]);
		}
	}
	if(num!=0)
		return ival;
	// high card - 0
	ival=0;
	ival=ival-15*value(cards[0][1]);
	ival=ival-value(cards[1][1]);
	ival=ival+value(cards[2][1]);
	ival=ival+15*value(cards[3][1]);
	ival=ival+15*15*value(cards[4][1]);
	return ival;
}

void print(int b,int w)
{
	if(b>w)
		printf("Black wins\n");
	else if(b<w)
		printf("White wins\n");
	else
		printf("Tie\n");
}

int main()
{
	int i=0;
	long time_start, time_end;
	struct timeval tv;
	gettimeofday(&tv,NULL);
	time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
	while(input())
	{
		int b=process(Black);
		int w=process(White);
		print(b,w);
	}
	gettimeofday (&tv, NULL);
	time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
	printf("Time:\t %ldms\n",time_end - time_start);
	return 0;
}
