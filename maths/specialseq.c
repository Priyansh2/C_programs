//let T(m,n)  = sigma(i^m), i=1 to i=n;
//this program calculates above T(m,n) for any m,n
#include<stdio.h>

long long int arr[10000][10000];


long long int f(long long int n , long long int k)
{
    long long int i,j;
    j=1;
    for(i=0;i<=k-1;i++)
        j = j*(n-i);

    return j;
}

long long int S2(long long int m ,long long int k)
{

    if(m>=1)
    {
        if(k==0 || k>m)
            return 0;

        else if(k==1)
            return 1;

        else{


            if(arr[m][k]!=-1)
                return arr[m][k]; 

            else
            {

                arr[m-1][k-1] = S2(m-1,k-1);
                arr[m-1][k] = S2(m-1,k);

                arr[m][k] = arr[m-1][k-1] + (k*arr[m-1][k]);

                return arr[m][k];         
            }
        }
        //return (S2(m-1,k-1) + k*(S2(m-1,k)));

    }

}

long long int T(long long int m ,long long int n)
{
    long long int i,j,k;

    j=0;

    if(m==0)
        return n;
    else{

        for(i=1;i<=m;i++)
        {
            j = j + ((S2(m,i)*f(n+1,i+1))/(i+1));

        }

        return j;

    }
}

int main()
{
    long long int i,j,k;
    long long int t,m,n;
 for(i=0;i<=10000-1;i++)
     for(j=0;j<=10000-1;j++)
         arr[i][j] = -1;
    
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&m,&n);

      //  for(i=0;i<=m+1;i++)
       // {
         //   for(j=0;j<=m+1;j++)
          //  {
            //    arr[i][j] = -1;
           // }}


        printf("%lld\n",T(m,n));
    }
    return 0;
}
