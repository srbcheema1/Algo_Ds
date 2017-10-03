/*
This code illustrates implementation of Jump Search in a sorted array.
*/
#include <iostream>
#include <math.h>
using namespace std;

int jumpSearch(int array[], int search, int size)
{
    int step = sqrt(size);                                  //Best Jump block size is sqrt(size) [Reference: http://www.geeksforgeeks.org/jump-search/]

    int location = 0;                                       //Store nearest found result while searching

    while (array[step-1] < search)                          //search for the element by jumping blocks while the current element is less that the one we
        {                                                   //are searching for.
            location = step;
            step += sqrt(size);
            if (location >= size)                           //If element not found till the end of array, return -1
                return -1;
        }

    while (array[location] < search)                        //If array element was greater than the element we are searching for, do a linear
        {                                                   //search from last known location.
            location++;
            if (location == step)
                return -1;
        }
    if (array[location] == search)
        return location;

    return -1;
}
int main()
{
    int array [] = {1,2,3,4,5,6,7,8,9,10}, search = 5, position;
    int size = sizeof(array)/ sizeof(array[0]);
    position = jumpSearch(array, search, size);
    if(position == -1)
        cout<<"Element is not present in array";
    else
        cout<<"Element is present at "<<position+1<<"th position";
    return 0;
}
