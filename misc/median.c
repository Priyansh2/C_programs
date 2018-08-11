
This algorithm works in two steps. The partitioning step works by picking some pivot element, then rearranging the elements of the array such that everything less than the pivot is to one side, everything greater than the pivot is to the other side, and the pivot is in the correct place.

In a simple words::

In a quick sort ,when you calls the Partition Function, and Lets say the partition Function returns 'Idx' , then the job of sorting 'Idx' position is Done, that is the A[Idx] contains the same element as the Idx th element of final answers (sorted Array) ,and all element to the left of 'Idx' is less than or equal to A[idx].

This is the main concept used by the selection Algorithm.

So to find the Medians basically our aim is to call recursively,the partitions functions unless the Pivot reached the N/ 2th element.

This is the implementation in C++ :

int A[MAX],N;
int partitions(int low,int high)
{
    int p=low,r=high,x=A[r],i=p-1;
    for(int j=p;j<=r-1;j++)
    {
        if (A[j]<=x)
        {

            i=i+1;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}
int selection_algorithm(int left,int right,int kth)
{
    for(;;)
    {
        int pivotIndex=partitions(left,right);          //Select the Pivot Between Left and Right
        int len=pivotIndex-left+1;

        if(kth==len)
            return A[pivotIndex];

        else if(kth<len)
            right=pivotIndex-1;

        else
        {
            kth=kth-len;
            left=pivotIndex+1;
        }
    }
}

Run this code calling the function , selection_algorithm(1,N,K),where K=N/2 (For median Elements)from the Main Function.
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
Note:: Using selection Algorithm ,we can't only find the Median elements without sorting , We can Find any Kth Smallest element .

Also ,note In partition Function,i selected the Pivot as the last element of Array( x=A[r] ).

You can improve the performance using the Randomized-Partition concept given in CLRS.

Hope this Helps!!!!!
