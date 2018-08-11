#include<stdio.h>
long long int arr[100000000];
long long int V(long long int n)//this function counts no's of 1 in binary representation of n
{
    long long int i,j,k;

    if(n==1)
        return 1;
        else if(n==0)
            return 0;
    else{

        if(arr[n]!=-1)
            return arr[n];
        else{
            arr[n/2] = V(n/2);
            arr[(n-1)/2] = V((n-1)/2);
arr[n] = (n&1)*(arr[(n-1)/2]+1) + (!(n&1))*(arr[n/2]);


            return arr[n];
        }
    }
}

int main()
{
    long long int i,j,k;
    long long int n,t;
for(i=1;i<=100000000;i++)
    arr[i] = -1;

    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);

      //  for(i=1;i<=n;i++)
      //  {
        //    arr[i] = -1;
       // }

        j = V(n);

        printf("%lld\n",j);
    }

    return 0;
}
