#include "ndv_math.h"

long factorial(int base)
{
        if(base==1) return 1;
        else return (base*factorial(base-1));

}

double q(float a,float b,float c)
{

	return (a*b)/(b+power(c,2));
}

long power(int base,int pow)
{
	long result=1;
	if((pow==0)&&(base==0)){
		fprintf(stderr,"Math error!\n");
		exit(-1);
	}
	if(pow==0)return 1;
	for(;pow>0;pow--){
		result*=base;
	}
	return result;
}
long sum_range(int start,int end)
{
	return (end+start)*(end-start+1)/2; 
}


