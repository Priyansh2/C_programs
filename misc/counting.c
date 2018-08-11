#include<stdio.h>
#define max 100000
long long int freq[100*max];

void counting_sort(const long long int arr[],long long int dup[], long long int res[] , long long int n){
    long long int i,j,k;
    long long int temp,min;

    for(i=1;i<=n;i++)
    {
        res[i] = 0;
    }
    min = arr[1];
    for(i=2;i<n;i++)
    {
        if(min>=arr[i])
            min = arr[i];
    }
    
    temp = 100*max;

    for(i=1;i<=temp;i++)
        freq[i] = 0;

    for(i=1;i<=n;i++)
        dup[i] = arr[i] - min;

    for(i=1;i<=n;i++)
        freq[dup[i]]++;

    for(i=1;i<=temp;i++)
        freq[i]+=freq[i-1];

    for(i=n;i>=1;i--)
    {
        j = dup[i];

        res[freq[j]-1] = j;
        freq[j]--;
    }


    for(i=1;i<=n;i++)
        res[i] = res[i] + min;

}

int main()
{
    long long int i,j,k;
    long long int n,t;
    long long int arr[max],res[max],dup[max];

    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);

        for(j=1;j<=n;j++)
        {
            scanf("%lld",&arr[j]);
        }
        counting_sort(arr,dup,res,n);

        for(k=1;k<=n;k++)
        {
            printf("%lld ",res[k]);
        }
        printf("\n");
    }

    return 0;
}
