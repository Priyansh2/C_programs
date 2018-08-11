//this program will do factorisation of input n using seive in O(log(n))
//but in this method we can give n upto 10^8
//this program outputs all prime factors(repetition allowed) of input n

//we can precompute all prime factors of numbers upto 10^6 in very efficient way
//by maintaining a 2d array of size 10000*10000

#include<stdio.h>
long long int minprime[100000000]={0};//this array will contain all prime less than equal to 10^8
long long int arr[100000000];//this array will contain all prime factors of input number n
void seive(long long int n)
{
    long long int i,j,k;
    for(i=2;i*i<=n;i++)
    {
        if(minprime[i]==0)
        {
            for(j=i*i;j<=n;j=j+i)
            {
                if(minprime[j]==0)
                    minprime[j] = i;
            }
        }
    }

    for(i=2;i<=n;i++)
    {
        if(minprime[i]==0)
        {
            minprime[i]=i;
        }
    }

}

long long int fact(long long int n)
{
    long long int i,j,k;
    i= 0;
    while(n!=0 && minprime[n]!=0)
    {

        i++;
        arr[i] = minprime[n];
        n = n/minprime[n];
    }
    return i;

}

int main()
{
    long long int i,j,n;
    long long int t,p,q,r;
    seive(100000000);//precomputation of all primes less than 10^8

    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);//taking input n
        if(n==1)
            printf("1");
        else{


            p = fact(n);//calculating prime factors of n

            for(j=1;j<=p;j++)
            {
                printf("%lld ",arr[j]);//printing all prime factors of n
            }
        }
        printf("\n");
    }

    return 0;
}
