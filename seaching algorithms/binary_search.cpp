/*
This code illustrates a recursive implementation of binary search in a sorted array.
*/
#include <iostream>
using namespace std;

int binarySearch(int array[], int left, int right, int search)
{
    if (right >= 1)
    {
        int mid = ((right-1)-left)/2;
        if (array[mid] == search)                                   //Checks if the element is present at the middle
            return mid;
        if (array[mid] > search)                                    //Since this is a sorted array, therefore if value of element is less than middle
            return binarySearch(array, left, mid-1, search);        //element, it lies in left part of array. Recursively searching again the left part.

        return binarySearch(array, mid+1, right, search);           //If element was neither in Middle nor in left part, it can only be in the right.
    }

    return -1;                                                      //If element was not found, return -1
}
int main()
{
    int array [] = {1,2,3,4,5,6,7,8,9,10}, search = 5, position;
    int size = sizeof(array)/ sizeof(array[0]);
    position = binarySearch(array, 0, size-1, search);            //here left index for binary search is sent as 0, while right as size - 1
    if(position == -1)                                                //therefore for an array of size 10, 9 will be sent (since arrays are 0 indexed)
        cout<<"Element is not present in array";
    else
        cout<<"Element is present at "<<position+1<<"th position";
    return 0;
}
