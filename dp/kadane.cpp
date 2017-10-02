#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,n,cur_max,max_fin;
	cin>>t;
	while(t--)
	{
	    
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
		cin>>arr[i];
		cur_max=arr[0];max_fin=arr[0];
		for(int i=1;i<n;i++)
		{
			cur_max=max(arr[i],cur_max+arr[i]);
			max_fin=max(max_fin, cur_max);
		}
		cout<<max_fin<<"\n";
	}
	return 0;
}
