//this function calculates a^b%m - O(log(b))
#include<stdio.h>

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

int main(){
    long long int a,b,m;
    long long int res,t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld %lld",&a,&b,&m);

        res = power_mod(a,b,m);

        printf("%lld\n",res);
    }

    return 0;
}
