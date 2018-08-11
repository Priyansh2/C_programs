// this function calculates no of trailing zeroes and digits in factorial(n) in base b
#include<stdio.h>
#include<math.h>
long long int min(long long int a, long long int b)
{
    if(a<b)
        return a;
        else return b;
}
void fun(long long int n ,long long int b)//n is number and b is base
{
    long long int noz,i,j,k,p,c;
 double ans;
 noz = n;
    j = b;
    for(i=2;i<=b;i++)
    {
        if(j%i==0)
        {
            p=0;
            while(j%i==0)
            {
                p++;
                j= j/i;
            }
            c=0;
            k=n;

            while((k/i)>0)
            {
                c = c + k/i;
                k = k/i;
            }

            noz = min(noz,c/p);
        }
    }


ans = 0;
for(i=1;i<=n;i++)
{
    ans = ans + log(i);
}

ans = ans/log(b);
ans = ans + 1.0;
ans = floor(ans);

printf("%lld %0.0lf\n",noz,ans);

}


int main()
{
    long long int t,n,b;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&b);

        fun(n,b);
        }

        return 0;
}
