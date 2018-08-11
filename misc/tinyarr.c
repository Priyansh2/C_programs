#include<stdio.h>
#include<math.h>

long long int sum[16777216];

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
		if(sum[i]<sum[j])
		{
			b[k++]=sum[i++];
		}
		else
		{
			b[k++]=sum[j++];
		}
	}

	while(i<=r1)
	{
		b[k++]=sum[i++];
	}
	while(j<=r2)

	{
		b[k++]=sum[j++];

		}


	for(i=l1;i<=r2;i++)
	{
		sum[i]=b[i-l1];
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
long long int power(long long int base,long long int exp)
{
	long long int result = 1;
	while (exp)
	{
		if(exp & 1)
		result*=base;
		exp >>=1;
		base*=base;
	}
	return result;
}




int main()
{
	long long int x,i;
	scanf("%lld",&x);
	long long int a[2*x],c;
	c=power(4,x);
	for(i=0;i<x;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=0;i<x;i++)
	{
		a[(2*x)-1-i]=-a[i];
	}
	long long int j;
	for(i=0;i<c;i++)
	{    
		sum[i]=0;
		for(j=0;j<2*x;j++)
		{
			if((i>>j)&1)
				sum[i]=sum[i]+a[j];
		}
	}

       sort(0,c-1);



	long long int N,z,flag=0;
	scanf("%lld",&N);
	while(N--)
	{       
		long long int st=0,end=c,key,mid,flag=0;	
		scanf("%lld",&key);
		while(st<=end)
		{
			mid=st+((end-st)/2);
			flag=0;
			if(sum[mid]==key)
			{
				printf("YES\n");
				flag++;
				break;
			}
			else if((st==end||end-st==1) && sum[mid]!=key)
			{
				printf("NO\n");
				break;
			}
			else if(sum[mid]<key)
			{
				st=mid;
			}
			else if(sum[mid]>key)
			{
				end=mid;
			}
		}



	}

	return 0;
}
