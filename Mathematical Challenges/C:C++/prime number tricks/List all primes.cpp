/*
This code illustrates that all primes are of the form (6k +- 1)
Please note this also includes some non-prime numbers such as 25 (6*4 + 1)
But ALL primes greater than 2 and 3 are included in this form and the non-primes
can be weeded out with a simple IF statement.
If the user needs to operate on (lets say 100) primes, instead of doing primality test on
all 1 to 100 numbers it will only have to test on 34 numbers.
*/

#include <iostream>
using namespace std;
int main()
{
    int numofprimes = 10, prime;
    for (int i = 2; i<numofprimes; i++)
    {
        prime = ((6*i) - 1);
        cout<<prime<<endl;
        prime = ((6*i) + 1);
        cout<<prime<<endl;
    }
    return 0;
}
