//this function will convert any number in base 10 to any other base b

#include<stdio.h>

void convert10tob(long long int n , long long int b)
{
    long long int i,j,k;
    if(n==0)
        return;

        i = n%b;
        n = n/b;
        if(i<0)
            n = n+1;

convert10tob(n,b);
j = i<0 ? (i+(b*(-1))) : i;

printf("%lld",j);

return;

}

int main()
{
    long long int n,b;
long long int t,i,j,k;
scanf("%lld",&t);
while(t--)
{
    scanf("%lld %lld",&n,&b);

    if(n!=0)
    {
        convert10tob(n,b);
        printf("\n");
    }


    else
        printf("0\n");

}

return 0;
}
