#include <bits/stdc++.h>
using namespace std;

int eggdrop(int n, int k)
{
    int eggs[n+1][k+1];
    for(int i=1;i<=n;i++)
    {
        eggs[i][0]=0;
        eggs[i][1]=1;
    }
    for(int i=1;i<=k;i++)
    {
        eggs[1][i]=i;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=k;j++)
        {
            eggs[i][j]=INT_MAX;
            for(int x=1; x<=j; x++)
            {
                int res = 1+max(eggs[i-1][x-1], eggs[i][j-x]);
                if(res<eggs[i][j])
                eggs[i][j]=res;
            }
        }
    }
    return eggs[n][k];
}

int main() {
    int t, n, k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        cout<<eggdrop(n,k)<<"\n";
    }
	return 0;
}
