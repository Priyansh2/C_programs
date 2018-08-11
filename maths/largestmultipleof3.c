#include<stdio.h>
long long int a[100000000];
long long int d[100000000];
void merge(long long int l1,long long int r1,long long int l2,long long int r2)
{
    long long int i,j,k=0;
    i=l1;j=l2;
    long long int len1,len2;
    len1 = r1-l1+1;
    len2 = r2-l2+1;
    long long int b[len1+len2];

    while(i<=r1 && j<=r2)
    {
        if(a[i]<a[j])
        {
            b[k++]=a[i++];
        }
        else
        {
            b[k++]=a[j++];
        }
    }

    while(i<=r1)
    {
        b[k++]=a[i++];
    }
    while(j<=r2)

    {
        b[k++]=a[j++];

    }


    for(i=l1;i<=r2;i++)
    {
        a[i]=b[i-l1];
    }
}

void sort(long long int l,long long int r)
{
    long long int mid = (l+r)/2;
    if(l==r)
        return;
    else
    {	sort(l,mid);
        sort(mid+1,r);
        merge(l,mid,mid+1,r);
    }
}

int main()
{
    long long int t,i,j,k;
    long long int n,m,temp,sum,res;
    long long int x,y,z;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);

        for(i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);

        }

        sort(1,n);


        x=n+1;
        for(j=1;j<=n;j++)
        {
            x--;
            d[x] = a[j];
        }

        sum=0;
        for(j=1;j<=n;j++)
            sum+=d[j];

        temp = n+1;
        while(sum!=0)
        {
            if(sum%3==0)
                break;

            temp--;
            sum = sum - d[temp];
        }

        for(k=1;k<=temp-1;k++)
            printf("%lld",d[k]);

        printf("\n");
    }

    return 0;
}
