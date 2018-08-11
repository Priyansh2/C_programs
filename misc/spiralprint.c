#include<stdio.h>
#include<stdlib.h>


void sort_rows(long long int *arr,long long int n)
{

    long long int i,j,k;
    long long int key;

    for(i=1;i<n;i++)

    {

        key=arr[i];
        j=i-1;
        while(j>=0 && key<arr[j]){

            arr[j+1]=arr[j];
            j--;

        }

        arr[j+1]=key;

    }

}
void spiral(long long int arr[][100], long long int m , long long int n)
{

    long long int top,bottom,right,left;
    long long int dir,i,j,k;

    top =0;        right = n-1;

    bottom = m-1;   left = 0;

    dir = 0;

    while(left<=right && top<=bottom)
    {

        if(dir==0)
        {
            for(i=left;i<=right;i++)

                printf("%lld ",arr[top][i]);
            top++;
        }

        else if(dir==1)
        {
            for(i=top;i<=bottom;i++)
                printf("%lld ",arr[i][right]);
            right--;
        }
        else if(dir==2)
        {
            for(i=right;i>=left;i--)
                printf("%lld ",arr[bottom][i]);

            bottom--;
        }


        else if(dir==3)
        {
            for(i=bottom;i>=top;i--)
                printf("%lld ",arr[i][left]);

            left++;
        }

        dir = (dir+1)%4;

    }


}

int main()
{
    long long int a[100][100];
    long long int i,j,k;
    long long int p,q,r;
    long long int t;
    long long int m,n;
    scanf("%lld",&t);

    for(p=1;p<=t;p++)
    {

        scanf("%lld %lld",&m,&n);//m - rows and n - cols

        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {  
                scanf("%lld",&a[i][j]);
            }
        }


        printf("\n");


//        for(k=0;k<m;k++)
  //      { 
    //        sort_rows(a[k],n);
      //  }


        /*for(i=0;i<m;i++)
          {
          for(j=0;j<n;j++)
          {  
          printf("%lld ",a[i][j]);
          }

          printf("\n");

          }

          printf("\n");
          */


        spiral(a,m,n);


        printf("\n");
    }
    return 0;
}


