// radix sort//-----practical fast sorting algorithm//
#include<stdio.h>

long long int getMax(long long int arr[], long long int n)
{
    long long int max = arr[0],i;
	for (i= 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

// A function to do counting sort of arr[] according to the digit represented by exp.//

void countSort(long long int arr[], long long int n, long long int exp)
{
	long long int output[n]; // output array//
	long long int i, count[10] = {0};

	// Store count of occurrences in count[]//
	
    for (i = 0; i < n; i++)
		{
        count[(arr[i]/exp)%10]++;
        }

// Change count[i] so that count[i] now contains actual position of this digit in output[]//
	
    for (i = 1; i < 10; i++)
		{
        count[i] = count[i] + count[i - 1];
        }

	// Build the output array//
	
    for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i]/exp)%10] - 1] = arr[i];
		count[(arr[i]/exp)%10]--;
	}

// Copy the output array to arr[], so that arr[] now contains sorted numbers according to current digit//
	
    for (i = 0; i < n; i++)
	{
    arr[i] = output[i];
    }
}


void radixsort(long long int arr[], long long int n)
{
    // Find the maximum number to know number of digits//
	
    long long int m = getMax(arr, n),exp;

// Do counting sort for every digit. Note that instead of passing digit number, exp is passed. exp is 10^i,where i is current digit number//
	
    for (exp = 1; (m/exp) > 0; exp=exp*10)
		{
        countSort(arr, n, exp);
        }
}

int main()
{
	long long int i,j,k,t;
    long long int n,m;
    long long int a[100000];
    
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
    
    scanf("%lld",&n);
    
    for(j=0;j<n;j++)
    {
    
    scanf("%lld",&a[j]);
    
    }
	
    radixsort(a,n);
	
    for(k=0;k<n;k++)
    {
    
    printf("%lld ",a[k]);
    
    }
    
    printf("\n");
    
    }	
    return 0;
}
