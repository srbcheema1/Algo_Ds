//http://codeforces.com/contest/429/problem/B
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int N = 1001;
int bs[N][N];
int be[N][N];
int gs[N][N];
int ge[N][N];
int calorie[N][N];

int maxcalorie(int n ,int m)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            bs[i][j] = calorie[i][j] + max(bs[i-1][j],bs[i][j-1]);
        }   
    }
    for (int i = n; i >=1; i--)
    {
        for (int j = 1; j <= m; j++)
        {
            gs[i][j] = calorie[i][j] + max(gs[i+1][j],gs[i][j-1]);
        }
        
    }
    for (int i = n; i >=1 ; i--)
    {
        for (int j = m; j >=1; j--)
        {
            be[i][j] = calorie[i][j] + max(be[i+1][j],be[i][j+1]);
        }
        
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >=1; j--)
        {
            ge[i][j] = calorie[i][j] + max(ge[i-1][j],ge[i][j+1]);
        }
        
    }
    int ans=0;
    for (int i = 2; i < n; i++)
    {
        for (int j = 2; j < m; j++)
        {
            int ans1 = bs[i][j-1] + be[i][j+1] + gs[i+1][j] + ge[i-1][j];
            int ans2 = bs[i-1][j] + be[i+1][j] + gs[i][j-1] + ge[i][j+1];
            
            ans = max(ans,max(ans1,ans2));
        }
        
    }
    return ans;
}
int main()
{
    memset(bs,0,sizeof bs);
    memset(be,0,sizeof be);
    memset(gs,0,sizeof gs);
    memset(gs,0,sizeof ge);
    memset(calorie,0,sizeof calorie);
    int n,m;
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin>>calorie[i][j];
        }
        
    }
    cout<<maxcalorie(n,m);
    return 0;
}