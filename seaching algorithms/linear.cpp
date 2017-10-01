/*
This code illustrates how Linear Search works
*/
#include <iostream>
using namespace std;
int main()
{
    int array [] = {1,2,3,4,5,6,7,8,9,10}, search = 5, position;
    for(position = 0 ; position < 10 ; position++)
        if(search == array[position])
            cout<<search<<" was found at "<<position+1<<"th position in the given array.";
    return 0;
}
