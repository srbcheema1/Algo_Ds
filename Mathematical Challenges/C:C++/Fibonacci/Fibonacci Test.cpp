/*
This code illustrates an easier and faster way to check whether a number is
a Fibonacci Number or not.
*/
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int num;                                //Number to be tested
    float chk;
    for (num = 1; num < 100 ; num++)
    {
        chk = sqrt(5*pow(num,2) + 4);
        if(chk - (int)chk == 0)
            cout<<num<<endl;
        chk = sqrt(5*pow(num,2) - 4);
        if(chk - (int)chk == 0)
            cout<<num<<endl;
    }
    return 0;
}
