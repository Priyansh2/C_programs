//this program gives all divisors of a number n as output

#include<stdio.h>
long long int arr[100000000];//this array stores all divisors of n
long long int  fun(long long int n)
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

int main(){
    long long int i,j,k;
    long long int t,n;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);

        j = fun(n);

        for(i=1;i<=j;i++)
        {
            printf("%lld ",arr[i]);
        }

        printf("\n");
    }

    return 0;
}
