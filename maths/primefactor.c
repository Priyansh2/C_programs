//this program will compute prime factors of given input n in O(sqrt(n))
//here we can give 19 digit input number as here we put all prime factors
//of n in arr[] of size 10^8(a 19 digit number cant have this much factors)

#include<stdio.h>

long long int arr[100000000];//contains all prime factors of n(repetition allowed)

long long int fact(long long int n)
{
    long long int i,j,k;
    j = 0;
    for(i=2;i*i<=n;i++)
    {
        
        while(n%i==0)
        {
            j++;
            arr[j] = i;
            n = n/i;
        }
    }
    if(n!=1)
    {
        j++;
        arr[j] = n;
    }

    return j; //returning last index of arr
}


int main()
{
    long long int t,i,j;
    long long int k;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&i);//taking input n

        if(i==1)
            printf("1");
        else{

            k =  fact(i);//calculating prime factors of n

            for(j=1;j<=k;j++)
                printf("%lld ",arr[j]);//printing all prime factors of n
        }
        printf("\n");

    }

    return 0;
}
