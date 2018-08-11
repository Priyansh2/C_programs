//this program will compute fib(n) in O(log(n)) upto n = 92
#include<stdio.h>
#include<limits.h>
long long int f[93];//as fib(93) contains digit upto 19 
//after that we wont able to store result in (long long int) format

long long int fib(long long int n)
{
    long long int i,j,k;
    if(n==1)
        return 1;
    if(n==0)
        return 0;
    else{
        i = (n+1)/2;

        if(f[i-1]==0)
            f[i-1] = fib(i-1);

        if(f[i]==0)
            f[i] = fib(i);

        if(n%2==0)
            return (2*f[i-1] + f[i])*f[i];

        else
            return f[i-1]*f[i-1]  + f[i]*f[i];
    }
}

int main()
{
    long long int i,j,k;
    long long int t,n;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);

        if(n>=0 && n<=92)
        {
            i = fib(n);
            printf("%lld\n",i);
        }
        else
            printf("number is too large to compute fibonacci\n");
    }
    return 0;
}
