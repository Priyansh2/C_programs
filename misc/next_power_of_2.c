//this program calculates next power of 2
#include<stdio.h>
#include<math.h>

long long int next_power(long long int x)
{
    long long int res,i,j,k;
    double next_num = ceil(log2(x));
    //i = long long int(next_num);
 res=1;
 i = floor(next_num);
 if(x&(x-1))//if x is not power of 2
     k = i;
     else
         k = i+1;
 for(j=1;j<=k;j++)
    {
        res*=2;
    }

    return res;
}

int main()
{
    long long int i,j,k;
    scanf("%lld",&i);
    while(i--)
    {
        scanf("%lld",&j);

        k=next_power(j);

        printf("%lld\n",k);


}

return 0;
}
