//this program is to find out nCr%M using seive
#include<stdio.h>
long long int arr[100000000];
long long int countfact(long long int n ,long long int p)
{
    long long int k= 0;
    while(n>0)
    {
        k = k + n/p;
        n = n/p;
    }

    return k;
}
long long int power_mod(long long int a, long long int b, long long int m)
{
    long long int temp,r;
    temp = a%m;
    r = 1;
    if(b==0 && m==1)
        return 0;
    else{


        while(b>0)
        {
            if(b%2==1)
            {
                r = r*temp;
                r = r%m;
            }
            b = b/2;
            temp = (temp*temp)%m;
        }

        return r;
    }
}

long long int ncr_modm(long long int  n , long long int r , long long int m)
{
    long long int res,i,j,k;
    res = 1;
    long long int x;
    for(x=1;x<=n;x++)
        arr[x] = 1;
        for(i=2;i<=n;i++)
        {
            if(arr[i]==1)
            {
                for(j=2*i;j<=n;j=j+i)
                {
                    arr[j] = 0;
                }
                k = countfact(n,i)- countfact(r,i) - countfact(n-r,i);
                res = (res*power_mod(i,k,m))%m;
            }
 
 }

return res;
}


int main()
{
    long long int t,n,r,res;
    long long int i,j,k,m;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld %lld",&n,&r,&m);

        res = ncr_modm(n,r,m);

        printf("%lld\n",res);

    }

    return 0;
}
