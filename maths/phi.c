//implementation of euler totient function

#include<stdio.h>
#include<math.h>
//long long int arr[10000000];
long long int striker[100000000];
long long int loader[100000000];
long long int c[1][2];
long long int ans[100000000];

long long int phi(long long int n)
{
    long long int res = n,i,j,k;
    long long int count=0;
    j=0;
    k =0;
    for(i=2;i*i<=n;i++)
    {
        count = 0;
        if(n%i==0)
        {
            k++;
            loader[k] = i;//stores all prime factors of n;

            while(n%i==0)
            {
                n = n/i;
                count++;//final value of count gives freq. of particular pf of n

            }
           /* j++;
            arr[j] = count;//storing freq. in arr*/
            res = res - res/i; 

        }
    }

    if(n!=1)//if originally n is prime or after(residue) n becomes prime
    { 
        k++;
        loader[k] = n;
        count++;
        res = res - res/n;
       /* j++;
        arr[j] = count;*/

    }
    c[1][1] = j;
    c[1][2] = k;

    return res;
}

long long int  strike(long long int n)
{
    long long int i,j,k;
    long long int mark;
    long long int x,y,z;

    for(x=1;x<=n;x++)
        striker[x] = 0;

    i = c[1][2];
    for(j=1;j<=i;j++)
    {
        k = loader[j];
        mark =1;
        while(k*mark<=n)
        {
            striker[k*mark] = -1;
            mark++;
        }
    }
    z=0;
    for(y=1;y<=n;y++)
    {
        if(striker[y]==0 && y<n)
        {
            z++;
            ans[z] = y;
        }
    }
return z;

}
int main()
{
    long long int i,j,k;
    long long int n;
    scanf("%lld",&i);
    while(i--)
    {
        scanf("%lld",&n);

        printf("\n%lld\n",phi(n));
j = strike(n);

for(k=1;k<=j;k++)
{
    printf("%lld ",ans[k]);
}

printf("\n");

    }


    return 0;
}
