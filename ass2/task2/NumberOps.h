#include<stdlib.h>
#include<string.h>
/*
Design Number ADT with the following operations ( NumberOps.h )
ii) Number add(Number a, Number b) : adds two numbers a and b and returns the result. If a and b are
represented in the same base then the result should be in the same base. If not, the number in the smaller
base should be converted to the larger of the two bases for addition and the result should be represented in
the larger base.
iii) Number subtract(Number a, Number b) : subtracts b from a and returns the result. Follow the same
convention as in addition vis-à-vis bases.
*/
Number createNumber(char *number_format)
{
	Number myNum;
	digit d;
	char* ch;
	ch=number_format;
	int base=0;
	while(*ch!=' ')
	{
		base = base*10 + (*ch-'0');
		ch++;
	}
	ch++;
	int length=0;
	digit* digitPtr;
	digitPtr=(digit*)malloc(sizeof(digit));
	digitPtr=NULL;
	digit* lastPtr;
	lastPtr=(digit*)malloc(sizeof(digit));
	lastPtr=NULL;
	while(*ch!='\n' && *ch!='\0')
	{
		if ((*ch>='a' && *ch<='z') || 
    		(*ch>='A' && *ch<='Z') || 
    		(*ch>='0' && *ch<='9'))
    	{
    		length++;
    		digit* nextDigit;
			nextDigit=(digit*)malloc(sizeof(digit));
			nextDigit->next=NULL;
			nextDigit->data=*ch;
    		if(digitPtr==NULL)
    		{
    			digitPtr=nextDigit;
    			lastPtr=nextDigit;
    		}
    		else
    		{
    			lastPtr->next=nextDigit;
    			lastPtr=nextDigit;
    		}
    	}
		ch++;
	}
	myNum.base=base;
	myNum.length=length;
	myNum.digits=digitPtr;
	return myNum;
}
/*
Number convert(Number n, int to_base) : converts the number n to a number of base to_base and
returns it. This is primarily a helper function used for adding and subtracting numbers of different
bases. Note that since convert is a helper function this needs to be visible only inside NumberOps.c
and hence should be declared static
*/
static Number convert(Number n,int to_base)
{
	Number myNum;
	myNum.base=to_base;
	int base=n.base;
	long int num=0;
	digit* d;
	d=n.digits;
	while(d!=NULL)
	{
		if(lookup(d->data)==-1)
			printf("Error!");
		//printf("(%c,%d)",d->data,lookup(d->data));
		num = num*base + lookup(d->data);
		d=d->next;
	}
	//printf("binary: %ld\n", num);
	char* revNum;
	int length=0;
	revNum = (char*)malloc(sizeof(char)*100);
	while(num>0)
	{
		char str[2];
		str[0]=Base[num%to_base];
		char revNumX[100];
		strcpy(revNumX,revNum);
		revNum=strcat(revNumX,str);
		length++;
		num=num/to_base;
	}
	//printf("%s\n",revNum);
	//revNum=(char*)realloc(revNum,length+1);
	digit* digitPtr;
	digitPtr=(digit*)malloc(sizeof(digit));
	digitPtr=NULL;
	int i=0;
	while(i<length)
	{
		digit* nextDigit;
		nextDigit=(digit*)malloc(sizeof(digit));
		nextDigit->next=NULL;
		nextDigit->data=revNum[i];
		if(digitPtr==NULL)
		{
			digitPtr=nextDigit;	
		}
		else
		{
			nextDigit->next=digitPtr;
			digitPtr=nextDigit;
		}
		i++;
	}
	myNum.length=length;
	myNum.digits=digitPtr;
	return myNum;
}

Number add(Number a, Number b)
{
	int to_base;
	if(a.base > b.base)
	{
		to_base=a.base;
		b=convert(b,to_base);
	}
	else
	{
		to_base=b.base;
		a=convert(a,to_base);
	}
	digit* d;
	d=a.digits;
	long int num1=0,num2=0;
	while(d!=NULL)
	{
		if(lookup(d->data)==-1)
			printf("Error!");
		//printf("(%c,%d)",d->data,lookup(d->data));
		num1 = num1*to_base + lookup(d->data);
		d=d->next;
	}
	d=b.digits;
	while(d!=NULL)
	{
		if(lookup(d->data)==-1)
			printf("Error!");
		//printf("(%c,%d)",d->data,lookup(d->data));
		num2 = num2*to_base + lookup(d->data);
		d=d->next;
	}
	long int result;
	result=num1+num2;
	Number myNum;
	char* revNum;
	int length=0;
	revNum = (char*)malloc(sizeof(char)*100);
	while(result>0)
	{
		char str[2];
		str[0]=Base[result%to_base];
		char revNumX[100];
		strcpy(revNumX,revNum);
		revNum=strcat(revNumX,str);
		length++;
		result=result/to_base;
	}
	//printf("%s\n",revNum);
	//revNum=(char*)realloc(revNum,length+1);
	digit* digitPtr;
	digitPtr=(digit*)malloc(sizeof(digit));
	digitPtr=NULL;
	int i=0;
	while(i<length)
	{
		digit* nextDigit;
		nextDigit=(digit*)malloc(sizeof(digit));
		nextDigit->next=NULL;
		nextDigit->data=revNum[i];
		if(digitPtr==NULL)
		{
			digitPtr=nextDigit;	
		}
		else
		{
			nextDigit->next=digitPtr;
			digitPtr=nextDigit;
		}
		i++;
	}
	myNum.base=to_base;
	myNum.length=length;
	myNum.digits=digitPtr;
	return myNum;
}

Number subtract(Number a, Number b)
{
	int to_base;
	if(a.base > b.base)
	{
		to_base=a.base;
		b=convert(b,to_base);
	}
	else
	{
		to_base=b.base;
		a=convert(a,to_base);
	}
	digit* d;
	d=a.digits;
	long int num1=0,num2=0;
	while(d!=NULL)
	{
		if(lookup(d->data)==-1)
			printf("Error!");
		//printf("(%c,%d)",d->data,lookup(d->data));
		num1 = num1*to_base + lookup(d->data);
		d=d->next;
	}
	d=b.digits;
	while(d!=NULL)
	{
		if(lookup(d->data)==-1)
			printf("Error!");
		//printf("(%c,%d)",d->data,lookup(d->data));
		num2 = num2*to_base + lookup(d->data);
		d=d->next;
	}
	long int result;
	result=num1-num2;
	Number myNum;
	char* revNum;
	int length=0;
	revNum = (char*)malloc(sizeof(char)*100);
	while(result>0)
	{
		char str[2];
		str[0]=Base[result%to_base];
		char revNumX[100];
		strcpy(revNumX,revNum);
		revNum=strcat(revNumX,str);
		length++;
		result=result/to_base;
	}
	//printf("%s\n",revNum);
	//revNum=(char*)realloc(revNum,length+1);
	digit* digitPtr;
	digitPtr=(digit*)malloc(sizeof(digit));
	digitPtr=NULL;
	int i=0;
	while(i<length)
	{
		digit* nextDigit;
		nextDigit=(digit*)malloc(sizeof(digit));
		nextDigit->next=NULL;
		nextDigit->data=revNum[i];
		if(digitPtr==NULL)
		{
			digitPtr=nextDigit;	
		}
		else
		{
			nextDigit->next=digitPtr;
			digitPtr=nextDigit;
		}
		i++;
	}
	myNum.base=to_base;
	myNum.length=length;
	myNum.digits=digitPtr;
	return myNum;
}

void printNumber(Number n)
{
	digit* digitPtr;
	digitPtr=(digit*)malloc(sizeof(digit));
	digitPtr=n.digits;
	while(digitPtr!=NULL)
	{
		printf("%c",digitPtr->data);
		digitPtr=digitPtr->next;
	}
	printf("(%d)",n.base);
}
