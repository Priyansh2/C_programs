//this program calculates sigma(k/gcd(k,n)) over k =1 to n ( both inclusive)
#include<stdio.h>
long long int arr[100000000];
long long int phi(long long int n)
{
    long long int res = n,i,j,k;

    for(i=2;i*i<=n;i++)
    {
               if(n%i==0)
               {
                   while(n%i==0)
                   n = n/i;

                   res = res - res/i;
      
               }
}

    if(n!=1)
      { 
          res = res - res/n;
         
      }

        return res;
}

long long int divisor(long long int n)
{
    long long int i,j,k;
    j=0;
    for(i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if((n/i)!=i)
            {
               j++;
               arr[j] = i;
                j++;
                arr[j] = n/i;
            }

            else
            {
                j++;
                arr[j] = i;
            }
        }
    }

return j;
}

long long int fun(long long int n)
{
    long long int i,j,k;
    j = divisor(n);
long long int sum;
sum = 0;
    
    for(i=1;i<=j;i++)
    {
        //k = k + phi(
        k = arr[i];
sum = sum + phi(k)*k;
    
    }

sum = (sum+2)/2;
    
    return sum;
}

int main()
{
    long long int t,n,i,j,k;

    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);

        i = fun(n);

        printf("%lld\n",i);
    }

    return 0;
}


