#include <iostream>
using namespace std;

#define s 12 //I gave space in the array as 12,but you can give the number you want.

int ternary_search (int v[],int n, int left, int right, int x);
int main()
{
    int v[s];
    short x;
    for(int i = 1; i <= s; i++)
    {
        v[i-1] = i;
    }
    cout << "Enter number for research:\n";
    cin >> x;

    int left = s/3;
    int right = (s/3)*2;

    if(ternary_search(v,s,left-1,right-1,x) == -1)
    {
        cout<<"Number does not exist in array.\n";
    }
    else
    {
        cout<<"The index is:"<<ternary_search(v,s,left-1,right-1,x)<<"\n";
    }
    return 0;
}
int ternary_search (int v[],int n, int left, int right, int x)
{

    if(left < 0 || right > n-1 || left > right)
    {
        return -1;
    }
    if(x == v[left])
    {
        return left;
    }

    if(x == v[right])
    {
        return right;
    }

   // Update the two index left and right if the element is not found.


    if(x < v[left])
    {
        return ternary_search(v,n,left-1,right,x);
    }

    if (x > v[left] && x < v[right])
    {

        return ternary_search(v,n,left+1,right-1,x);
    }

    if(x > v[right])
    {
        return ternary_search(v,n,left,right+1,x);
    }
}
