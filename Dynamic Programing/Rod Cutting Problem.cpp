#include <iostream>
#include <math.h>
using namespace std;

int maxprofit(int arr[],int n)
{
    int t[n+1][n+1];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            if(i==0 || j==0)
                t[i][j] = 0;
   
        
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(i<= j)
                t[i][j]= max(arr[i-1] + t[i][j-i] , t[i-1][j]);
            else
                t[i][j]= t[i-1][j];
        }
  
    return t[n][n];
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    cout<<maxprofit(arr,n)<<endl;
	    
	}
	return 0;
}
