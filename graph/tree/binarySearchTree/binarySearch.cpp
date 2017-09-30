#include<bits/stdc++.h>
#define ulli long long
using namespace std;

int gcd(int a, int b)
{
    // Everything divides 0 
    if (a == 0 || b == 0)
       return 0;
 
    // base case
    if (a == b)
        return a;
 
    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

vector<ulli> primeFactorise(ulli num)
{
    vector<ulli> myvect;
    for(int i=2; i<=num; i++)
    {
        if(num%i==0)
        {
            myvect.push_back(i);
        }
    }
    return myvect;
}

ulli binSearch(vector<ulli> myvect, ulli a, ulli s, ulli e, ulli min)
{
    ulli mid=(s+e)/2;
    if(s>e)
        return min;
    if(s==e)
    {
        if(myvect[s]==a)
            return a;
        else if(myvect[s]<a)
            return myvect[s];
        else
            return min;
    }
    else if(myvect[mid]==a)
    {
        return myvect[mid];
    }
    else if(myvect[mid]<a)
    {
        min=myvect[mid];
        return binSearch(myvect, a, mid+1, e, min);
    }
    else
    {
        return binSearch(myvect, a, s, mid-1, min);
    }
}

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ulli a, b;
    cin>>a>>b;
    if(a>b)
    {
        ulli temp=a;
        a=b;
        b=temp;
    }
    ulli gcda=gcd(a, b);
    vector<ulli> myvect;
    myvect=primeFactorise(gcda);
    ulli q;
    cin>>q;
    while(q--)
    {
        ulli l, r;
        cin>>l>>r;
        ulli ans=binSearch(myvect, r, 0, myvect.size()-1, 0);
        if(ans>=l)
            cout<<ans<<endl;
        else
            cout<<"-1"<<endl;
    }
}
