//Time Complexity: O(logn)
#include<bits/stdc++.h>
using namespace std;
int main()
{

    int a[100],n,i,beg,end,mid,item;
    cout<<"Enter No. of Elements= ";
    cin>>n;
    cout<<"Enter Elements in Sorted Order=\n";
    for(i=1;i<=n;i++)
    cin>>a[i];

    cout<<"Enter Item you want to Search= ";
    cin>>item;

    beg=1;
    end=n;

    mid=(beg+end)/2;

    while(beg<=end && a[mid]!=item)
    {
        if(a[mid]<item)
            beg=mid+1;
        else
            end=mid-1;
        mid=(beg+end)/2;
    }
    if(a[mid]==item)
        cout<<"Data is Found at Location : "<<mid;
    else
        cout<<"Data is Not Found";

return 0;
}
