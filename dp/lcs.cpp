#include<iostream>
#include<cstring>
using namespace std;

int lcs(string s1,string s2,int i,int j){
    if(i==0||j==0){
        return 0;
    }

    if(s1[i-1]==s2[j-1]){
        return  1 + lcs(s1,s2,i-1,j-1);
    }
    return max(lcs(s1,s2,i,j-1),lcs(s1,s2,i-1,j));
}

int lcsMatrix(string s1,string s2) {
    int dp[100][100];
    int l1 = s1.length();
    int l2 = s2.length();

    for(int i=0;i<=l1;i++){
        for(int j=0;j<=l2;j++){
            if(i==0||j==0){
                dp[i][j] = 0;
                continue;
            }
            else if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    for(int i=0;i<=l1;i++){
        for(int j=0;j<=l2;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    int x = l1;
    int y = l2;
    while(x>0 && y>0){
        if(dp[x][y]==dp[x-1][y-1]+1){
            cout<<s1[x-1]<<" ";
            x--;
            y--;
        }
        else if(dp[x][y]==dp[x-1][y]){
            x = x - 1;
        }
        else{
            y = y - 1;
        }
    }


return dp[l1][l2];
}
int main(){
    string s1 = "Apple";
    string s2 = "anarpAplist";

    int i = s1.length();
    int j = s2.length();

    cout<<lcs(s1,s2,i,j)<<endl;
    cout<<lcsMatrix(s1,s2)<<endl;

return 0;
}
