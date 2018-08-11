//this program prints powerset of given set as input
//input set can be set of integer or that of characters
// can calculate esaily upto string of length 10^61
#include<stdio.h>
#include<string.h>
char arr[1000000000];//array of 10^9 and still no seg fault
int main()
{
    long long int n,t,size,temp;
    long long int i,j,k;
   // char arr[100];
    scanf("%lld",&t);
    while(t--){

        scanf("%s",arr);//original set 

        n = strlen(arr);
        size = 1;

        for(i=1;i<=n;i++)
        {
            size*=2;//final size is 2^n -- no of elements in powerset
        }

        for(j=1;j<=size;j++)//running loop from 1 to 2^n
        {
            temp = j;

            for(k=0;k<n;k++)
            {
                if(1&temp)
                    printf("%c ",arr[k]);

                temp = temp>>1;
            }

            printf("\n");
        }

    }

    return 0;
}
