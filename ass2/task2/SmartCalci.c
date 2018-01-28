#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Base.h"
#include "BaseOps.h"
#include "Number.h"
#include "NumberOps.h"

#define llu long long unsigned int
#define ll long long int
int main(int argc, char** argv)
{
	if(argc!=3)
	{
		printf("Invalid number of arguments\n");
		exit(0);
	}
	FILE* f1;
	FILE* f2;
	f1 = fopen(argv[1], "r");
	f2 = fopen(argv[2], "r");
    if (f1 == NULL || f2==NULL)
    {
        printf("Cannot open the files\n");
        exit(0);
    }
    initializeBase(f1);
    char operation[10];
    char operand1[128];
    char operand2[128];
    while(fgets(operation, sizeof(operation), f2) != NULL )
	{
		fgets(operand1, sizeof(operand1), f2);
		fgets(operand2, sizeof(operand2), f2);
		Number num1,num2,result;
		num1=createNumber(operand1);
		num2=createNumber(operand2);
		printNumber(num1);
		if(strcmp(operation,"add\n")==0)
		{
			result=add(num1,num2);
			printf(" + ");
		}
		else if(strcmp(operation,"subtract\n")==0)
		{
			result=subtract(num1,num2);
			printf(" - ");
		}
		else
		{
			printf("Invalid choice!\n");
		}
		printNumber(num2);
		printf(" = ");
		printNumber(result);
		printf("\n");
	}
    
    fclose(f2);
    fclose(f1);
	return 0;
}
