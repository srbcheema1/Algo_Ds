//Libraries Included
#include<iostream>
#include<algorithm>
using namespace std;
 

/* 

int findMedian()  -> Returns the median of the input array.
int partition()   -> The partition work is done by this function.
int kthSmallest() -> The recursive function that performs the major calculations
                     of finding the kthSmallest element only on the condition that the 
                     value of k is less than the size of the array produced after after 
                     every recursive cycle. 
int main()        -> Driver Function.
*/


/*
predefined stuff ->

sort()
swap()
INT_MAX
*/
int findMedian(int arr[], int size_of_array)
{
    sort(arr, arr+size_of_array);  // Sort the array
    return arr[size_of_array/2];   // Return middle element
}

int partition(int arr[], int low, int high, int variable_to_be_found)
{
    // Search for variable_to_find in arr[low..high] and move it to end
    int i;
    for (i=low; i<high; i++)
        if (arr[i] == x)
           break;
    swap(&arr[i], &arr[high]);
 
    // Standard partition algorithm
    i = l;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

 
int kthSmallest(int arr[], int low, int high, int k)
{   
    // If k is smaller than number of elements in array
    if (k > 0 && k <= high - low + 1)
    {
        int n = high-low+1; // Number of elements in arr[low..high]
 
        // Divide arr[] in groups of size 5, calculate median
        // of every group and store it in median[] array.
        int i, median[(n+4)/5]; // There will be floor((n+4)/5) groups;
        for (i=0; i<n/5; i++)
            median[i] = findMedian(arr+low+i*5, 5);
        if (i*5 < n) //For last group with less than 5 elements
        {
            median[i] = findMedian(arr+low+i*5, n%5); 
            i++;
        }    
 
        // Find median of all medians using recursive call.
        // If median[] has only one element, then no need
        // of recursive call
        int medOfMed = (i == 1)? median[i-1]:
                                 kthSmallest(median, 0, i-1, i/2);
 
        // Partition the array around a random element and
        // get position of pivot element in sorted array
        int pos = partition(arr, low, high, medOfMed);
 
        // If position is same as k
        if (pos-l == k-1)
            return arr[pos];
        if (pos-l > k-1)  // If position is more, recur for left
            return kthSmallest(arr, low, pos-1, k);
 
        // Else recur for right subarray
        return kthSmallest(arr, pos+1, high, k-pos+l-1);
    }
 
    // If k is more than number of elements in array
    return INT_MAX;
}
 
// It searches for x in arr[l..r], and partitions the array 
// around x.

 int main()
{
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr)/sizeof(arr[0]), k = 3;
    cout << "K'th smallest element is "
         << kthSmallest(arr, 0, n-1, k);
    return 0;
}