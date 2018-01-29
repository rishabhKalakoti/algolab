#include<stdlib.h>
#include<stdio.h>
extern int maxD;
extern char* Base;
int initializeBase(FILE *basefile)
{
    char ch = fgetc(basefile);
    while (ch != EOF)
    {
    	if ((ch>='a' && ch<='z') || 
    		(ch>='A' && ch<='Z') || 
    		(ch>='0' && ch<='9'))
    		maxD++;
    	if(ch=='\n')
    		break;
    	ch = fgetc(basefile);
    }
    Base = (char*)malloc(maxD * sizeof(char));
    fseek(basefile, 0, SEEK_SET);
    ch = fgetc(basefile);
    int i=0;
    while (ch != EOF)
    {
    	if ((ch>='a' && ch<='z') || 
    		(ch>='A' && ch<='Z') || 
    		(ch>='0' && ch<='9'))
    	{
    		Base[i]=ch;
    		i++;
    	}
    	if(ch=='\n')
    		break;
    	ch = fgetc(basefile);
    }
    return maxD;
}
int lookup(char c)
{
	int i;
	for(i=0;i<maxD;i++)
	{
		if(Base[i]==c)
		{
			return i;
		}
	}
	return -1;	
}
