//this program calculates a^b%m where a is matrix and b and m are positive integers
#include<stdio.h>

void matrix_mult(long long int arr[][100] , long long int brr[][100] , long long int res[][100] , long long int m ,long long int mod)
{  
    //here we store product of arr[][] and brr[][] into res[][]
    //m is size of square matrix arr[][] and brr[][]
    long long int i,j,k;
    long long int sum;

    for(i=1;i<=m;i++)
    {
        for(j=1;j<=m;j++)
        {
            sum = 0;
            for(k=1;k<=m;k++)
            {
                sum = sum + ((arr[i][k]%mod)*(brr[k][j]%mod)); //res = arr*brr
                // res[i][j] = sum%mod;
            }
            res[i][j] = sum%mod;
        }
    }
    return;
}

void powermod(long long int arr[][100] ,long long int res[][100],long long int m ,long long int n,long long int mod)
{
    //as above did here also we store ans into res[][]
    //m is the size of square matrix arr[][]
    //n is power :- a^n%mod

    long long int i,j,k;

    for(i=1;i<=m;i++)//making res = 1 , which means identity matrix
    {
        for(j=1;j<=m;j++)
        {
            if(i==j)
                res[i][j] = 1;
            else
                res[i][j] = 0;
        }}


    if(n==1)//if n==1 return arr
    {
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=m;j++)
            {
                arr[i][j] = arr[i][j]%mod;
            }}

        return ;
    }

    else{

        while(n>0)
        {
            if(n%2==1)
            {
                matrix_mult(res,arr,res,m,mod);//res = res*arr


            }

            matrix_mult(arr,arr,arr,m,mod);//arr = arr*arr
            n = n/2;
        }
        return ;
    }
}

int main(){

    long long int i,j,k;
    long long int arr[100][100];
    long long int ans[100][100];
    long long int t,m,mod;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld %lld",&m,&k,&mod);//m is size of arr , k is power , mod is modvalue
        printf("\n\n");
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=m;j++)
            {
                scanf("%lld",&arr[i][j]);
            }}

        powermod(arr,ans,m,k,mod);
        printf("\n\n");
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=m;j++){
                printf("%lld ",ans[i][j]);
            }

            printf("\n");
        }

        printf("\n");
    }

    return 0;
}


