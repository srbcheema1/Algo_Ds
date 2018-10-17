/*
This code illustrates how Linear Search works
*/
#include <iostream>  //header file
using namespace std;
int main()   //main function start
{
    int search;
    cin search;
    int array [] = {1,2,3,4,5,6,7,8,9,10}, position;  //creating an array of 10nos and two integers
    for(position = 0 ; position < 10 ; position++)    //traversing on array
        if(search == array[position]){     // compare nos of array and no which we need to search
            cout<<search<<" was found at "<<position+1<<"th position in the given array.";  //printed no.
        }
        else{
            cout<<"NOT FOUND!";
    return 0;
}
