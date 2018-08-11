//this program calculates catalan number upto 30 in O(n)

#include<stdio.h>
//long long int arr[100000000];
//arr[0] = 1;

long long int n_choose_k(long long int n ,long long int k)
{
    long long int res = 1;
    long long int i,j;
    if(k>n-k)
    {
        k = n- k;
    }

    for(i=0;i<=k-1;i++)
    {
        res = (res*(n-i))/(i+1);
       // res = res/(i+1);
    }

    return res;
}

long long int catalan(long long int n)
{
   // if(n==0)
      //  return 1;
        long long int i,j,k;
    
    long long int ans;
    
  //  for(i=1;i<=n;i++)
//    {

    ans = n_choose_k(2*n,n);
    ans = ans/(n+1);
//arr[i] = ans;
  //  }
   return ans;
}

int main(){
    long long int i,j,k;
    scanf("%lld",&i);
    while(i--)
    {
        scanf("%lld",&j);

        k = catalan(j);
        printf("%lld\n",k);
    }

    return 0;
    }
