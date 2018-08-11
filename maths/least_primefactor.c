//this function finds least prime factor of n
#include<stdio.h>
long long int arr[100000000];
long long int isprime(long long int n)
{
    long long int i,j,k;
    j=0;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
         {
             j=1;
             break;
         }
    }

    if(j==0)
        return 1;//number is prime
        else
            return 0;

            }
long long int least_pf(long long int n)
{
    long long int i,j,k;

if(isprime(n))
    j = n;
else{

    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if(isprime(i))
            {
                j = i;
                break;
               
            }
        }
    }
}
return j;
}

int main()
{
    long long int i,t,n;
    long long int j,k;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);

        j = least_pf(n);
printf("%lld\n",j);
}
return 0;
}
