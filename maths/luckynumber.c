//i can do this in 0(sqrt(n)) which also works for n upto 10^19 and in less than 1 sec 
// Program to check whether input number is a lucky number or not. 

// lucky number is a number which have at least three prime factors 

// eg: 4 = 2*2(two pf, so it is not a lucky number) 
// eg: 100 = 2*2*5*5(four pf, so it is a lucky number) 
// eg: 30 = 2*3*5(three pf, so it is a lucky number) 

# include <stdio.h> 
# include <math.h> 
 
// A function to print all prime factors of a given number n 
long long int pf(long long int n) 
{ 
    // Print the number of 2s that divide n 
    long long int a=0,b=0,c=0; 
    while (n%2 == 0) //takes(O(log(n)))
    { 
 
 a++; //printf("%d", 2); 
 
 n = n/2; 
    } 
 
    // n must be odd at this point. So we can skip one element that is i = i +2
    // because odd +2 == odd
long long int i; 
 
for (i = 3; i <= sqrt(n); i = i+2) //takes(O(sqrt(n)))
    { 
 
 // While i divides n, print i and divide n 
 
 while (n%i == 0) 
 
 { 
 
 b++;    //printf("%lld", i); 
 
 n = n/i; 
 
 } 
    } 
 
    // This condition is to handle the case when n is a prime number 
    // greater than 2 
    if (n > 2) 
    c++;    //printf ("%lld",n); 
   
    return a+b+c; 
} 
 
/* Driver program to test above function */ 
long long int b[100000]; 
int main() 
{     long long int n,t,i,j,k,x,y; 
   
    scanf("%lld",&t); 
    for(i=1;i<=t;i++) 
    {   y=0; 
 
scanf("%lld",&n); 
      for(k=2;k<=100000;k++) 
      { 
 
  
 
if(pf(k)>=3) 
 
{ 
 
b[y]=k; // array containing all lucky numbers from 2 to 100000//
 
y++; 
 
} 
 
} 
 
printf("%lld\n",b[n-1]);// printing nth lucky number//   
    } 
    return 0; 
} 
 
 
