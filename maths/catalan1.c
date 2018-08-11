//this program is even more faster to compute catalan number upto 33
#include<stdio.h>
long long int arr[34];
long long int catalan(long long int n)
{
    if(n==0)
        return 1;
        else{

            if(arr[n]!=-1)
                return arr[n];
                else{
                    arr[n-1] = catalan(n-1);
arr[n] = (2*(2*n -1)*arr[n-1])/(n+1);
            //return (2*(2*n - 1)*catalan(n-1))/(n+1);
            return arr[n];
                }
        }
}

int main(){
    long long int i,j,k;
    scanf("%lld",&i);
    for(j=1;j<=34;j++)
        arr[j] = -1;

    while(i--){
        
        scanf("%lld",&k);
        printf("%lld\n",catalan(k));
    }
    return 0;
    }
