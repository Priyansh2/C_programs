//this program calculates no of terms in farey seq. of order n

#include<stdio.h>
#include<math.h>

long long int phi(long long int n)
{
    long long int res = n,i,j,k;

    for(i=2;i<=sqrt(n);i++)
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

long long int f(long long int n)
{
    long long int i,j,k;
j=0;
    for(i=1;i<=n;i++)
    {
        j = j + phi(i);
    }

    k = 1+ j;

    return k;
}

int main()
{
    long long int n,t;

    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);

    printf("%lld\n",f(n));

    }

    return 0;
}
