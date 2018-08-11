#include<stdio.h>
long long int a[1000000];
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
	long long int i,j,k,t;
	scanf("%lld",&t);
	for(i=i;i<=t;i++)
{
	scanf("%lld",&j);
	for(k=0;k<j;k++)
	{
		scanf("%lld",&a[k]);
	}
		sort(0,j-1);

		for(k=0;k<j;k++)
		{
			printf("%lld\t",a[k]);
		}

printf("\n");
}

return 0;
}

