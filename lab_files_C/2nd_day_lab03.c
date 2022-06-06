#include<stdio.h> 
#include<math.h> 
 
int main(){ 
double a,b; char ch; 
printf("Enter the operator (+,-,*,/,%%)\n"); 
scanf("%c",&ch); 
printf("Enter the two number \n"); 
scanf("%lf %lf",&a,&b); 
switch(ch) 
{ 
case '+': 
printf("value of %lf + %lf = %lf",a,b,a+b); 
break; 
case '-': 
printf(" value of %lf - %lf = %lf",a,b,a-b); 
break; 
case '*': 
printf("value of %lf * %lf = %lf",a,b,a*b); 
break; 
case '/': 
if(b!=0) 
{ 
printf("value of %lf / %lf = %lf",a,b,a/b); 
break; 
} 
else{ 
printf("value of b can not be zero"); 
break; 
} 
case '%': 
printf("value of %lf %% %lf = %lf",a,b,remainder(a,b)); 
break; 
default: 
printf("Enter valid operator"); 
} 
return 0;
}