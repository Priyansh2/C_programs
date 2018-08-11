//q sort for floating numbers

#include<stdio.h>
#include<stdlib.h>

int cmp(const void*a  , const void *b)
{
    float x = *(const float*)a;
    float y = *(const float*)b;
if(x>y)
    return 1;
    else if(x<y)
        return -1;

        else return  0;
}


int main()
{
    float arr[100];
    int i,j,k;
int y,t,z,x,n,m;
    
    scanf("%d",&t);

    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);

        for(j=1;j<=n;j++)
        {
            scanf("%f",&arr[j]);
        }

     qsort(&arr[1],n,sizeof(float),cmp);


     for(k=1;k<=n;k++)
     {
         printf("%f ",arr[k]);

     }

     printf("\n");

    }

return 0;
}

