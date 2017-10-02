#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int w, int weight[], int val[])
{
    int K[n+1][w+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(i==0||j==0)
                K[i][j]=0;
            else
            {
                if(weight[i-1]<=j)
                    K[i][j] = max(val[i-1] + K[i-1][j-weight[i-1]],  K[i-1][j]);
                else
                    K[i][j] = K[i-1][j];
            }
        }
    }
    return K[n][w];
}

int main() {
	int t,n,w;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    cin>>w;
	    int val[n], weight[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>val[i];
	    }
	    for(int i=0;i<n;i++)
	    {
	        cin>>weight[i];
	    }
	    cout<<knapsack(n,w,weight,val)<<"\n";
	}
	return 0;
}
