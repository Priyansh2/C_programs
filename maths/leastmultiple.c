#include<stdio.h>
#define max 10000000
long long int arr[max];

int isprime(long long int n)
{
    int flag = 0;
    long long int i,j,k;

    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            flag=1;
               break;
        }
    }

    if(flag==0)
return 1;
    else 
        return 0;
}

long long int fun(long long int n)
{
    long long int res,i,j,k;
j = 0;

long long int p,q,r;
    for(i=2;i<=n;i++)
    {
        if(isprime(i)==1)
        {
            j++;
            arr[j] = i;
        }
    }
    r = 1;
     for(k=1;k<=j;k++)
     {
        p = arr[k];
q = 1;
        while(q<=n)
        {
            res = q;
            q = q*p;
        }
r = r*res;

     }

     return r;
}


int main()
{
    long long int t,n,i,j,k;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
         scanf("%lld",&n);

         printf("%lld\n",fun(n));

    }

    return 0;
}
    

      


