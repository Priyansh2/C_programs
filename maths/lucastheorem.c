//this program calculates C(n,r)%m 

#include<stdio.h>

long long int fact_pow(long long int n, long long int p)
{
	long long int r=0;
	while(n>=p)
	{
		r = r + n/p;
		n = n/p;
	}
	return r;
}
long long int fastmod(long long int a, long long int b, long long int m)
{
	long long int res=1;

	if(b==0)
		return 1%m;

	else{
		while(b>0)
		{
			if(b&1)
				res = (res*a)%m;

			a = (a*a)%m;

			b = b/2;
		}
	}
	return res;
}
long long int inversemod(long long int n, long long int m)
{
	return fastmod(n,m-2,m);
}

long long int main_fun(long long int n, long long int m)
{
	long long int r=1;
	long long int temp,i,j,k;

	while(n>0)
	{
		temp = n%m;

		for(i=2;i<=temp;i++)
		{
			r = (r*i)%m;
		}
		n = n/m;
		if(n%2==1)
		{
			r = m - r;
		}
	}
	return r;
}

long long int combmod(long long int n , long long int k, long long int m)
{
	long long int a,b,c;
	long long int p,q,r;
    long long int s,t;

	if(n<k || n<0 || k<0)
	{ return 0;
	}
	else if(m==0 && n!=k)
	{
		return 0;
	}

	else if((m==0 || m==1) && n==k){
		return 0;
	}
	else if(n==k && m!=0 && m!=1)
	{
		return 1;
	}

	else if(k==0 && n!=0 && (m==0 || m==1))
	{
		return 0;
	}
	else if(k==0 && n!=0 && m!=0 && m!=1)
	{      
		return 1;
	}
	else if(n>k)
	{  
		a = fact_pow(n,m);
		b = fact_pow(k,m);
		c = fact_pow(n-k,m);

		if(a>(b+c))
		{
            return 0;
		}
		else{

			p = main_fun(n,m);
			q = main_fun(k,m);
			r = main_fun(n-k,m);

            s = inversemod(q,m);
            t = inversemod(r,m);

			return (p*(s*t)%m)%m;
		}
	}
}

int main()
{
	long long int a,b,c,i,j,k;

	scanf("%lld",&a);

	for(i=1;i<=a;i++)
	{
		scanf("%lld %lld %lld",&b,&c,&k);

		j = combmod(b,c,k);
		printf("%lld\n",j);
	}
	return 0;
}


