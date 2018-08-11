//this is the fastest possible algorithm to count primes upto given n
//this program calculates all primes upto given n in least possible time
//this program is faster than seive in calculating primes upto 10^9 
#include<stdio.h>
#include<math.h>
#define max 100000000
long long int u[max];
long long int v[max];
long long int prime[max];
long long int gen_primes(long long int n)
{
    long long int i,j,k;
    long long int temp;
    long long int p,q,r;
    long long int m,x;
    p = sqrt(n);
    i = (1 + p)/6;//no of iteration
    k = ((n+1)/6) + 1;//bitset no:
    for(r=1;r<=k;r++)
    {
        u[r] = 1;
        v[r] = 1;
    }


    for(j=1;j<=i;j++)
    {

        if(v[j]==1)
        {
            m = 6*j-1;
            temp = m - j;
            q = 1;
            u[n] = 0;
            while((j+q*m)<=(k-1) && (temp+q*m)<=(k-1))
            {
                v[j+q*m]=0;
                u[temp+q*m] = 0;
                q++;
            }

            if((j+q*m)<=(k-1))
                v[j+q*m] = 0;
            if((temp+q*m)<=(k-1))
                u[temp+q*m] = 0;
        }
        if(u[j]==1)
        {
            m = 6*j + 1;
            temp = m - j;
            v[temp] = 0;
            q=1;
            while((j+q*m) <=(k-1) && (temp+q*m)<=(k-1))
            {
                u[j+q*m]=0;
                v[temp+q*m] = 0;
                q++;
            }
            if((j+q*m)<=(k-1))
                u[j+q*m] = 0;
            if((temp+q*m)<=(k-1))
                v[temp+q*m] = 0;
        }


    }
    x = 0;
    x++;
    prime[x] = 2;
    if(n!=2)
    {
        x++;
        prime[x] = 3;
    }
    for(r=1;r<=k-1;r++)
    {
        if(v[r]==1 && (6*r-1)<=n)
        {

            x++;
            prime[x] = 6*r - 1;
        }
        if(u[r]==1 && (6*r+1)<=n && r!=4)
        {
            x++;
            prime[x] = 6*r + 1;
        }
    }

    return x;
}

int main()
{
    long long int i,j,k;
    long long int n,t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        if(n==1)
            printf("1 is neither prime nor composite\n");
        else{

            i = gen_primes(n);
            printf("Total primes less than or equal to n is :- %lld\n",i);
            for(j=1;j<=i;j++)
                printf("%lld ",prime[j]);

            printf("\n");
        }
    }
    return 0;
}
