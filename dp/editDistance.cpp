#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

inline int min(int a,int b,int c){
    return min(a,min(b,c));
}

int dp[100][100];

int editDistance(string a,string b,int m,int n){
    if(m==0)
        return n;
    if(n==0)
        return m;
    if(dp[m][n]!=-1)
        return dp[m][n];
    int ans=0;
    if(a[m-1]==b[n-1])
        ans=editDistance(a,b,m-1,n-1);
    else
        ans=1+min(editDistance(a,b,m-1,n),editDistance(a,b,m,n-1),editDistance(a,b,m-1,n-1));
    return dp[m][n]=ans;
}
int main(){
    memset(dp,-1,sizeof(dp));
    string a,b;
    a="coding";
    b="hacking";
    cout<<editDistance(a,b,a.length(),b.length());
}
