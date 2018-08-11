//this is the fastest way to implement any divisor function 
//works well for n upto 10^19
#include<stdio.h>
long long int arr[100000000];//contain all prime factors of n
long long int freq[100000000];//contain freq of all distinct prime factors
long long int loader[100000000];
long long int isprime(long long int n)
{
 
 long long int i,j,k;
 j=0;
 for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            j = 1;
            break;
        }

    }

    if(j==0)
        return 1;
        else 
            return 0;
}
long long int fact(long long int n)
{
    long long int i,j,k;
    j = 0;
//if(isprime(n))
//{
    //j++;
  //  arr[j] = n;
//}
//else{

    for(i=2;i*i<=n;i++)
    {

        while(n%i==0)
        {
            j++;
            arr[j] = i;
            n = n/i;
        }
    }
    if(n!=1)
    {
        j++;
        arr[j] = n;
    }
//}
    return j; // returning last index of arr
}

long long int divisor_fun(long long int last_factor,long long int size)
{
    long long int i,j,k,res;
    j = last_factor;

    for(i=1;i<=j+1;i++)
       {
           freq[i] = 0;
           loader[i] = 0;
       }
    for(i=1;i<=size;i++)
    {
        freq[arr[i]]++;
    }
    k =0;
    for(i=1;i<=j+1;i++)
    {
        if(freq[i]!=0)
        {
            k++;
            loader[k] = freq[i] + 1;
        }

    }

    res = 1;
    for(i=1;i<=k;i++)
    {
        res  = res*loader[i];
    }
    return res;
}

int main()
{
    long long int i,j,k;
    long long int ans,n;
    long long int t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
  if(n==1)
      printf("1\n");
  
  else if(n!=1 && isprime(n)==1)
  {
      printf("2\n");
  }
  else{

  j = fact(n); //lastindex
        k = arr[j]; // last prime factor
        ans = divisor_fun(k,j);

        printf("%lld\n",ans);
}
    }

    return 0;
}
