#include <stdio.h>
#include <ctype.h>
#include "lab1.h"
//functions
int insertA( int a)
{
    do
    {
    
   printf("Введіть натуральне число: ");
    scanf("%s", input);

    int i = 0;
    while (input[i] != '\0') {
        if (!isdigit(input[i])) 
        {
            printf("Введене значення не є натуральним числом\n");
        }
        i++;
    }
    a = atoi(input);
    }
    while (a<=0);
    printf("Введене число: %d\n", a);
    return a;
}
int insertB( int b)
{
    do
    {
    
   printf("Введіть ціле число: ");
    scanf("%s", input);

    int i = 0;
    while (input[i] != '\0')
     {
        if (input[i]=='-')
        {
             
        }
        else
        {
        if (!isdigit(input[i])) 
        {
            printf("Введене значення не є цілим числом\n");
             f=0;
        }
        else{f=1;}
        }
        i++;
    }
    b = atoi(input);
    }
    while (f==0);
    printf("Введене число: %d\n", b);
    return b;
}
int insertC( int c)
{
    do
    {
    
   printf("Введіть ціле число: ");
    scanf("%s", input);

    int i = 0;
    while (input[i] != '\0') {
        if (!isdigit(input[i])) 
        {
            printf("Введене значення не є цілим числом\n");
        }
        i++;
    }
    c = atoi(input);
    }
    while (c==0);
    printf("Введене число: %d\n", c);
    return c;
}

int cube(int i,int d)
{
    result=d;
 do
  {
    result= result*d;
  i= i-1;
  } while (i>0);
  d=result;
  return d;
}

int sum(int a)
{
    printf("%i\n",cube(a,2));
return (1-cube(a,2))*(-1);
}

int modul(int a, int b,int c)
{
    if (((a*c)-b)<=0)
    {
        return ((a*c)-b)*(-1);
    }
    else
    {
      return((a*c)-b); 
    }
}

//main
int main(int argc, char const *argv[])
{
    A=insertA(a);
    B=insertB(b);
    C=insertC(c);
    printf("%d\n",A);
    printf("%d\n",B);
    printf("%d\n",C);
    printf("модуль=%i\n", modul(A,B,C));
    printf("куб=%i\n", cube(3, C));
     printf("сума=%i\n", sum(A));
    printf("значення виразу %i \n", modul(A,B,C)/cube(3,C)+sum(A));
    return 0;
}
