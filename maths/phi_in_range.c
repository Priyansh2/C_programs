//this program calculates (sum of phi upto given (l,r) range in which both l and r are included)modm;
//remember 10^9 + 7 and 10^7  + 9 are primes
#include<stdio.h>
#define m 1000000007
#define max 100000000
long long int phi[max];
long long int min(long long int a, long long int b)
{
    if(a<b)return a;
    else return b;
}
void totient(long long int l ,long long int r)
{
    long long int i,j,k;
    long long int temp,sum;
    phi[1] = 1;
    for(i=l;i<=r;i++)
        phi[i] = i;//indicates that phi[z] for any z is not evaluated yet
        //and is initialises for product formula
    if(l==1)
        temp = 2;
    else
        temp = min(l,2);
    for(j=temp;j<=r;j++)
    {
        if(phi[j]==j)//if phi[] is not computed yet then j is prime
                    // or if phi[] is already computed i,e j is prime
        {
            phi[j] = j- 1; // phi[prime] = prime -1;
            for(k=2*j;k<=r;k=k+j)//computing phi[] for other multiples of prime j
                                //by using product formula of phi
            {
                phi[k] = (phi[k]/j)*(j-1);
            }
        }
    }
    /*sum = 0;
      for(i=1;i<=n;i++)
      {
      sum = (sum + phi[i])%m;
      }
      sum = sum%m;

      return sum;*/
}

int main()
{
    long long int t,i,j,k;
    long long int l,r;
    totient(2,max/10);

    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&l,&r);
        k  = 0;
        //  j = totient(i);
        for(j=l;j<=r;j++)
        {
            k = (k+phi[j])%m;
        }


        printf("%lld\n",k%m);
    }

    return 0;
}
