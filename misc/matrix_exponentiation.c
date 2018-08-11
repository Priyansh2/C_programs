#include<stdio.h>
#include<stdlib.h>
//#define mod 1000000007
long long int **matrix_mul(long long int **m,long long int **n,long long int num,long long int mod)
{
    long long int i,j,k,**result;
    result = (long long int**)malloc(sizeof(long long int)*num);
    
    for(i=0;i<num;i++)
    {
        result[i] = (long long int*)malloc(sizeof(long long int)*num);
    }
    for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
        {
            result[i][j] = 0;
            for(k=0;k<num;k++)
            {
                result[i][j]+=((m[i][k])%mod*(n[k][j]%mod));
            }
            //   return result;
        }
    }
    return result;
}
long long int **mod_pow(long long int **matrix,long long int p ,long long int n ,long long int mod)
{
    long long int **m , i,j,k;
    m = (long long int **)malloc(sizeof(long long int)*n);
    for(i=0;i<n;i++)
    {
        m[i] = (long long int*)malloc(sizeof(long long int)*n);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
                m[i][j] = 1;
                else
                    m[i][j] = 0;
        }

    }

    if(p==0)
    {

        return m;

    }
        else if(p==1)
            {
                matrix = matrix_mul(m,matrix,n,mod);
                return matrix;
            }
            while(p)
            {
                if(p&1)
                   {
                       m = matrix_mul(m,matrix,n,mod);
                   }
                    p= p/2;

                    matrix = matrix_mul(matrix,matrix,n,mod);
            }

            return m;
}

int main()
{
    long long int i,j,k,p;
    long long int **matrix;
    long long int n,t;
    long long int mod;
    scanf("%lld",&t);
    while(t--)
    {
       scanf("%lld",&n);//size of square matrix;

        matrix = (long long int**)malloc(sizeof(long long int)*n);
        for(i=0;i<n;i++)
        {
            matrix[i] = (long long int*)malloc(sizeof(long long int)*n);
        }

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%lld",&matrix[i][j]);
            }
        }

       printf("\n");
       scanf("%lld %lld",&p,&mod);//power and mod value

        matrix = mod_pow(matrix,p,n,mod);

        printf("\n");

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                printf("%lld ",matrix[i][j]);
            }
            printf("\n");
        }

        printf("\n");
    }

    return 0;
}
