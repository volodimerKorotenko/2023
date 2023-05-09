#include <stdio.h>
#include "main.h"

int str_dig_check(char* s)
{
	int i=0;
	for(int i=0;(s[i]!='\0')&&(s[i]!='\n');i++)
	{
		if((s[i]<'0')||(s[i]>'9'))return -1;
	}
	return 0;
}

int read_int(char* msg)
{
	char str[BUF_SIZE]={0,};
	char c;
	int result;
	while(1)
	{
		fputs(msg,stdout);
		fgets(str,BUF_SIZE,stdin);
		if((str[BUF_SIZE-2]!='\0')&&(str[BUF_SIZE]!='\n'))
		{
			printf("Input value is too large!\n");
			str[BUF_SIZE-2]=0;
			continue;
		}
		if(str_dig_check(str)==-1){
			printf("Invalid input!\n");
			continue;
		}
		break;
	}
	sscanf(str,"%d",&result);
	return result;

}

int main()
{
	int a,b,c,d;
	double result;
	printf("This program calculates following expression:\n"
	"(AxB)/(B+C^2)+sum(D!) for D in range [0;B]\n");
	while(1)
	{
		a=read_int("Enter value A:");
		b=read_int("Enter value B:");
		c=read_int("Enter value C:");
		if(b+power(c,2)==0)
		{
			printf("Denominator must have non-zero value!\n");
			continue;
		}
		break;
	}
	result=q((float)a,(float)b,(float)c);
	printf("Result is:%f\n",result);
	
	return 0;
}

