// this programs calculates gcd(a,b) in fastest time //
// this algorithm is known as "binary_gcd"
#include<stdio.h>
long long int binarygcd(long long int u , long long int v)
{
    long long int k,i,t,j;
k = 0;
t=0;
while(!(u&1) && !(v&1))
{
    k++;
    u = u>>1;
    v = v>>1;
}

if(u&1)
    t=u;
    else t = (-1)*v;

    do{
        while(!(t&1))
            t=t>>1;

            if(t>0)
                u = t;
                else 
                    v = (-1)*t;

                    t = u-v;
    }while(t);

long long int res =1;
    for(i=0;i<k;i++)
        res = res*2;

        res = res*u;

        return res;
}

int main()
{
    long long int i,j,k;
    long long int a,b;

    scanf("%lld",&i);
    while(i--)
    {

        scanf("%lld %lld",&a,&b);

        printf("%lld\n",binarygcd(a,b));

    }

    return 0;
}
