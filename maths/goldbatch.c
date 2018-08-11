//in this problem we deals with goldbatch conjecture which
//states that for any integer >=4 there exits two primes
//p1 and p2 such that p1+p2=n

//the problem here is to find number of distinct pairs (p1,p2)
//satisfying condition in the conjecture above for given
//"even number" n

//Note:- pair (p1,p2) is such that p1<=p2 and n lies in between
//2^2 to 2^18(both inclusive)



//as p1<=p2 so p1<=n/2; so for pair(i,j) we have j = n-i;
//such that i and j(or n-i)are prime numbers and 2<=i<=(n/2)


//so consider function:- gen_primes() that generates primes upto 2^18
//and let prime[i] stores ith prime in the function
//now let count_pairs() to be another function which find total 
//number of pairs as per problem


#include<stdio.h>
#include<math.h>
#define max 100000000
long long int u[max];
long long int v[max];
long long int prime[max];
void gen_primes(long long int n)
{
    long long int i,j,k;
    long long int temp;
    long long int p,q,r;
    long long int m,x;
    p = sqrt(n);
    i = (1 + p)/6;//no of iteration
    k = ((n+1)/6) + 1;//bitset no:
    for(r=1;r<=k;r++)
    {
        u[r] = 1;
        v[r] = 1;
    }


    for(j=1;j<=i;j++)
    {

        if(v[j]==1)
        {
            m = 6*j-1;
            temp = m - j;
            q = 1;
            u[n] = 0;
            while((j+q*m)<=(k-1) && (temp+q*m)<=(k-1))
            {
                v[j+q*m]=0;
                u[temp+q*m] = 0;
                q++;
            }

            if((j+q*m)<=(k-1))
                v[j+q*m] = 0;
            if((temp+q*m)<=(k-1))
                u[temp+q*m] = 0;
        }
        if(u[j]==1)
        {
            m = 6*j + 1;
            temp = m - j;
            v[temp] = 0;
            q=1;
            while((j+q*m) <=(k-1) && (temp+q*m)<=(k-1))
            {
                u[j+q*m]=0;
                v[temp+q*m] = 0;
                q++;
            }
            if((j+q*m)<=(k-1))
                u[j+q*m] = 0;
            if((temp+q*m)<=(k-1))
                v[temp+q*m] = 0;
        }


    }
    for(r=1;r<=n;r++)
        prime[r] = 0;

    prime[2] = 1;
    prime[3] = 1;

    for(r=1;r<=k-1;r++)
    {
        if(v[r]==1 && (6*r-1)<=n)
        {
            prime[6*r-1] = 1;
        }
        if(u[r]==1 && (6*r+1)<=n && r!=4)
        {
            prime[6*r+1] = 1;
        }
    }

}

long long int count_pairs(long long int n){
    long long int i,res;
    res = 0;
    gen_primes(n);//O(nlog(log(n)))
    for(i=2;i<=n/2;i++)//O(n/2)==O(n)
    {
        if(prime[i]==1 && prime[n-i]==1 && n>=2*i && i<n)
            res++;

    }
    return res;
}//so overall complexity is O(nlog(log(n)))


int main()
{
    long long int t,i,j,n;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);//n should be even
        if(n%2==0)
        {
            i = count_pairs(n);
            printf("%lld\n",i);
        }
        else{
            printf("please enter even n\n");
        }
    }
    return 0;
}


