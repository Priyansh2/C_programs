//this is a program of sorting a 2d array row and column wise//
#include<stdio.h>

void sort_rows(long long int *arr, long long int n)

{
    long long int i;
	for(i=1;i<n;i++)
	{
		long long int key=arr[i];
		long long int j=i-1;
		while(j>=0 && key<arr[j])
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}

void sort_cols(long long int arr[][1000], long long int column)

{
	long long int key,k;
	long long int i,j;
	for(i=0;i<column;i++)
	{
		for(j=1;j<column;j++)
		{
			key=arr[j][i];
			k=j-1;
			while(k>=0 && arr[k][i]>key)
			{
				arr[k+1][i]=arr[k][i];
				k--;
			}
			arr[k+1][i]=key;
		}
	}
}
int main()
{
    
	long long int arr[1000][1000];
	long long int i,j,row_size,col_size;
	long long int k,x,y,z,t,n,m;
	
	scanf("%lld",&t);
	for(k=1;k<=t;k++)
	{
	    scanf("%lld %lld",&n,&m);
	
	for(x=0;x<n;x++)
	{
	    for(y=0;y<m;y++)
	    {
	        
	        scanf("%lld",&arr[x][y]);
	    }
	}
	
	
	printf("Original array:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%lld ",arr[i][j]);
			
		}
		printf("\n");
	}
	row_size=n;
	for(i=0;i<row_size;i++)
	{
		sort_rows(arr[i],m);
	}
	col_size=m;
	for(i=0;i<col_size;i++)
	{
		sort_cols(arr,col_size);
	}
	printf("Sorted Array:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%lld ",arr[i][j]);
			
		}
		printf("\n");
	}
	
	printf("\n");
	}
	return 0;
}
