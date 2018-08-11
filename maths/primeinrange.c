//finding prime in given range//
//there are 5761455 primes in range(1,10^8)
#include<stdio.h>
#include<math.h>

long long int prime[100000000];//r can be 10^8
//long long int storeprime[1000000];
long long int count;
long long int max(long long int a, long long int b)
{
    if(a>b)return a;
    else return b;
}
void primefinder(long long int l ,long long int r)
{
    long long int i,j,k;
    long long int temp=1;
count=0;
    for(i=1;i<=r-l+1;i++)
    prime[i]=1;

//    printf("%lld\n",prime[0]);

    //for(i=1;i<=1000000;i++)
      //  storeprime[i]=-1;

prime[0]=1;

    for(i=2;i<=sqrt(r);i++)
    {
        for(j=max(i*i,(l+i-1)/(i*i));j<=r;j=j+i)
        {
            prime[j-l] = 0;
        }
    }
    for(k=max(l,2);k<=r;k++)
    {
        
        if(prime[k-l]==1)
           {
               
               
               //printf("%lld ",prime[k-l]);
        //       storeprime[temp++] = k;
               
               count++;
           }
    }
}
int main()
{
 long long int t,i,j,k;
 long long int l,r;

 scanf("%lld",&t);
while(t--)
    {
        scanf("%lld %lld",&l,&r);

primefinder(l,r);



printf("%lld\n",count);
/*for(i=1;storeprime[i]!=-1;i++)
{
    printf("%lld ",storeprime[i]);

}

printf("\n");*/
}
return 0;
    }
