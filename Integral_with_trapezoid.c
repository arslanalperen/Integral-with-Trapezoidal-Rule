#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Integral_with_trapezoid.h"

float trapezoidrule(float sub_intervals,int power_counter,float initial_limit,int powers[],int coefficients[],int constant,float p,float deltax){
	
	int l,j;
	float number=0;
	float sum=0;
	float final_sum=0;
	
    for(l=1;l<sub_intervals;l++){
        for(j=0;j<power_counter;j++){
            number=initial_limit;
            number=pow(number,powers[j]);
            number=number*coefficients[j];
            sum=number+sum;
        	}
        	sum+=constant;
        
		for(j=0;j<power_counter;j++){
        	number=p;
        	number=pow(number,powers[j]);
        	number=number*coefficients[j];
        	sum=number+sum;
        	}
       		sum+=constant;
       		
        	sum = sum / 2;
        	sum*=(p-initial_limit);
        	final_sum += sum;
        	sum=0;
        	initial_limit = initial_limit + deltax;
        	p = p + deltax;
    }
    return final_sum;
}
