#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Integral_with_trapezoid.h"

int main()
{
    char function[50];
    int length,i,digit,coefficient,constant=0,coefficient_counter,power_counter;
    int coefficients[10];
    int powers[10];
    float initial_limit,final_limit,sub_intervals;
    
    printf("Enter the function (Ex: 3x^4+2x+5)\n");
    scanf("%s",function);
    printf("Enter the initial limit.\n");
    scanf("%f",&initial_limit);
    printf("Enter the final limit.\n");
    scanf("%f",&final_limit);
    printf("Enter the sub interval.\n");
    scanf("%f",&sub_intervals);
 
    i=0;
    digit=0;
    coefficient_counter=0;
    power_counter=0;
    coefficient=1;
 
    length=strlen(function);
                       
    while(i<length)        
    {
        if(function[i]=='+')
        {
            powers[power_counter]=coefficient;
            power_counter=power_counter+1;
            digit=0;
            coefficient=1;
        }
 
        if(function[i]=='x')
        {
            coefficients[coefficient_counter]=coefficient;
            coefficient_counter=coefficient_counter+1;
            digit=0;
            coefficient=1;
        }
 
        if(function[i]=='-')
        {
            if(function[i-1]=='^')
            {
                printf("The function which you entered is not valid.\n");
                return 0;
            }
            else
            {
                coefficient=coefficient*(-1);
            }
        }
 
 
        if(function[i]=='0'||function[i]=='1'||function[i]=='2'||
           function[i]=='3'||function[i]=='4'||function[i]=='5'||
           function[i]=='6'||function[i]=='7'||function[i]=='8'||
		   function[i]=='9')
        {

            digit = digit+1;
 
            if (digit>1)
            {
                coefficient = coefficient*10;
                coefficient = coefficient+(function [i]-'0');
 
            }
            else
            {
               	coefficient = coefficient*(function[i]-'0');
 
            }
            if ((i+1)==length)
            {
                if(function[i-1]!='^')
                {constant=coefficient;
                }
                else
                {
                constant=0;
                powers[power_counter]=coefficient;
                power_counter=power_counter+1;
                digit=0;
                coefficient=1;
                }
            }
        }
 
        i=i+1;
    }
 	
 	int y;
 	
    for(y=0;y<power_counter;y++){
    printf("\nCoefficient of %d. number: %d -- Power: %d \n",y+1,coefficients[y],powers[y]);
    }
    printf("Constant: %d\n",constant);
 
    float deltax,p;
 
    deltax=(final_limit-initial_limit)/sub_intervals;
    
    p=initial_limit+deltax;
    float final_sum;
    
	final_sum = trapezoidrule(sub_intervals,power_counter,initial_limit,powers,coefficients,constant,p,deltax);
        
    printf("\nTo the %s function, final answer is : |%f| \n",function,final_sum);
 
    return 0;
}
