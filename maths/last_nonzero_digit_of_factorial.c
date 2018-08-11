#include<stdio.h>
long long int P(long long int k)
{
    long long int arr[]={6,2,4,8};

    if(k<1)return 1;
    
    else
    return arr[k%4];
}

long long int L(long long int n)
{
    long long int arr[] = {1,1,2,6,4};

    if(n<5)
        return arr[n];
        else{
            return (P(n/5)*L(n/5)*L(n%5))%10;
        }
}

int main()
{
    long long int t,i,j;

    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&i);

        printf("%lld\n",L(i));
    }

    return 0;
}
