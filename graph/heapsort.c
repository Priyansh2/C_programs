#include<stdio.h>

//long long int a[100000];

void heapsort(long long int a[], long long int n)
{
    long long int i,j,k;
    long long int temp;


    for(i=1;i<n;i++)
    {
        j=i;

        do
        {
            k = (j-1)/2;             

            if (a[k] < a[j])
            {
                temp = a[k];
                a[k] = a[j];
                a[j] = temp;

            }

            j = k;

        } 
        while(j!=0);

    }

    for(i=(n-1);i>=0;i--)

    {

        temp = a[0];
        a[0] = a[i];   
        a[i] = temp;
        k=0;

        do 
        {
            j = (2*k)+1;    

            if((a[j] < a[j+1]) && (j < (i-1)))
            {
                j++;   }

            if((a[k] < a[j]) && (j<i))   

            {
                temp = a[k];
                a[k] = a[j];
                a[j] = temp;

            }

            k=j;

        } 
        while(k<i);

    } 

}




int main()
{
    long long int i,q,sum;
    long long int n,m;
    long long int l,r;
    long long int a[100000];

    scanf("%lld",&n);

    for (i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }

    heapsort(a,n);

    printf("\n The sorted array is : ");

    for(i=0;i<n;i++)
    {
        printf("%lld ",a[i]);
    }

    printf("\n");


    scanf("%lld",&q);

    for(i=1;i<=q;i++)
    {


        scanf("%lld",&m);

        l=0;
        
        r=(n-1);
        
        sum=0;
        while(l<r)
        {
            if((a[l]+a[r])<=m)
            {
                sum+=r-l;
                l++;
            }
            else 
            {
                r--;
            }
        }
        
        printf("%lld\n",sum);
    }
    return 0;
}
