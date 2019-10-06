#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n][n];
	    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];
	    
	    for(int k=0;k<n;k++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                if(a[i][j]>a[i][k]+a[k][j])a[i][j]=a[i][k]+a[k][j];
	            }
	        }
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(a[i][j]==10000000)cout<<"INF"<<" ";
	            else cout<<a[i][j]<<" ";
	        }
	        cout<<endl;
	    }
	    
	}
	return 0;
}
