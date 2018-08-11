//this function calculates sum of all divisors of a number n known as sigma(n)
//can be computed in O(sqrt(n))
#include<stdio.h>
long long int power[100000000];
long long int pf[100000000];
long long int isprime(long long int n)
{
    long long int i,j,k;


    j=0;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            j=1;
            break;
        }

    }

    if(j==0)
        return 1;
    else return 0;
}
long long int expo(long long int a,long long int b)
{
    long long int res = 1;
    if(b==0)
        return 1;
    else if(b==1)
        return a;
    else{

        while(b>0)
        {
            if(b&1)
            {
                res = res*a;
            }

            a = a*a;
            b = b/2;
        }
        return res;
    }
}

long long int ans[100000000];




long long int freq(long long int n)
{
    long long int i,j,k;
    long long int count ,res;
    long long int x,y,z;
    long long int flag=0;
    count = 0;
    x =0;
    y=0;
    if(n%2==0)
    {
        if((n&(n-1))==0)
            flag=1;


        y++;
        pf[y] = 2;

        while(n%2==0)
        {
            count++;
            n = n/2;
        }
        x++;
        power[x] = count + 1;
    }

    if(n%2==1 && flag==0)
    {


        for(i=3;i*i<=n;i=i+2)
        {
            count = 0;
            if(n%i==0)
            {
                y++;
                pf[y] = i;
                while(n%i==0)

                {
                    count++;
                    n = n/i;
                }
                x++;
                power[x] = count + 1;

            }
        }
        count=0;
        if(n!=1 && isprime(n)==1)
        {
            y++;
            pf[y] = n;
            count++;
            x++;
            power[x] = count + 1;
        }
    }

    return x;
}

long long int sigma(long long int n)
{
    long long int i,j,k;
    long long int temp,x,y,z;
    x=0;

    j = freq(n);

    for(i=1;i<=j;i++)
    {
        if(power[i]==-1)
            break;
        else{
            if(pf[i]!=n)
            {
                k = power[i];
                temp = pf[i];
                x++;
                ans[x] = (expo(temp,k) - 1)/(temp-1);
            }
        }

    }


    return x;
}

long long int final_ans(long long int n)
{
    long long int i,j,k;
    j =1;

    if(isprime(n))
        return n+1;
    else{


        k =  sigma(n);

        for(i=1;i<=k;i++)
        {
            j = j*ans[i];
        }
        return j;
    }

}
int main()
{
    long long int i,j,k;
    long long int t,n;
    scanf("%lld",&t);
    for(i=1;i<=100000000;i++)
        power[i] = -1;
    while(t--)
    {
        scanf("%lld",&n);
        if(n==1)
            printf("1\n");
        else{

            j = final_ans(n);
            printf("%lld\n",j);
        }
    }

    return 0;
}
