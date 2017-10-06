#include <iostream>
using namespace std;

int main() {
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int arr[n],lis[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	        lis[i]=1;
	    }
	    int max=1;
	    for(int i=1;i<n;i++)
	    {
	        for(int j=0;j<i;j++)
	        {
	            if(arr[j]<arr[i]&&lis[i]<lis[j]+1)
	            {
	                lis[i]=lis[j]+1;
	            }
	        }
	        if(lis[i]>max)
	        max=lis[i];
	    }
	    cout<<max<<"\n";
	}
	return 0;
}
