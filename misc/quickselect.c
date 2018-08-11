#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define INT_MAX pow(2,15) -1

int partition(int arr[], int l, int r, int k);

// A simple function to find median of arr[]. This is called
// only for an array of size 5 in this program.

//int arr[100];
void merge(int arr[],int l1,int r1,int l2,int r2)
{
	 int i,j,k=0;
	i=l1;j=l2;
	int len1,len2;
	len1 = r1-l1+1;
	len2 = r2-l2+1;
	int b[len1+len2];

	while(i<=r1 && j<=r2)
	{
		if(arr[i]<arr[j])
		{
			b[k++]=arr[i++];
		}
		else
		{
			b[k++]=arr[j++];
		}
	}

	while(i<=r1)
	{
		b[k++]=arr[i++];
	}
	while(j<=r2)

	{
		b[k++]=arr[j++];

		}


	for(i=l1;i<=r2;i++)
	{
		arr[i]=b[i-l1];
	}
}

void sort(int arr[],int low1,int high1)
{
	int mid = (low1+high1)/2;
	if(low1==high1)
		return;
	else
	{	sort(arr,low1,mid);
	      sort(arr,mid+1,high1);
	      merge(arr,low1,mid,mid+1,high1);
	}
}

int findMedian(int arr[], int low,int high,int n)
{
    sort(arr,low,high); // Sort the array
	
    return arr[n/2]; // Return middle element
}

 
// ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT
int kthSmallest(int arr[], int l, int r, int k)
{
	// If k is smaller than number of elements in array
	if (k > 0 && k <= r - l + 1)
	{
		int n = r-l+1; // Number of elements in arr[l..r]

		// Divide arr[] in groups of size 5, calculate median
		// of every group and store it in median[] array.
		int i, median[(n+4)/5]; // There will be floor((n+4)/5) groups;
		for (i=0; i<n/5; i++)
			median[i] = findMedian(arr,l+i*5,5*(i+1)-n+r,5);//(arr,low,high,number of elements)//
		if (i*5 < n) //For last group with less than 5 elements
		{
		i++;
			median[i] = findMedian(arr,l+i*5,r,n%5); 
		
		} 

		// Find median of all medians using recursive call.
		// If median[] has only one element, then no need
		// of recursive call
		int medOfMed = (i == 1)? median[i-1]:kthSmallest(median, 0, i-1, i/2);

		// Partition the array around a random element and
		// get position of pivot element in sorted array
		int pos = partition(arr, l, r, medOfMed);

		// If position is same as k
		if (pos-l == k-1)
			return arr[pos];
		if (pos-l > k-1) // If position is more, recur for left
			return kthSmallest(arr, l, pos-1, k);

		// Else recur for right subarray
		return kthSmallest(arr, pos+1, r, k-pos+l-1);
	}

	// If k is more than number of elements in array
	return INT_MAX;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// It searches for x in arr[l..r], and partitions the array 
// around x.
int partition(int arr[], int l, int r, int x)
{
	// Search for x in arr[l..r] and move it to end
	int i;
	for (i=l; i<r; i++)
		if (arr[i] == x)
		break;
	swap(&arr[i], &arr[r]);

	// Standard partition algorithm
	i = l;
	for (int j = l; j <= r - 1; j++)
	{
		if (arr[j] <= x)
		{
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[i], &arr[r]);
	return i;
}

// Driver program to test above methods
int main()
{
           int t,i,j,k;
	   int a,b,c,arr[100];
	   int n,m;
	   scanf("%d",&t);
	   for(i=1;i<=t;i++)
	   {
		   scanf("%d",&n);//size of array
		  for(j=0;j<n;j++)
		  {
			  scanf("%d",&arr[j]);

		  }
		  scanf("%d",&k);//kth smallest element 


	printf("K'th smallest element is\n",kthSmallest(arr, 0, n-1, k));
	   }

	return 0;
}
