class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        bool dp[n][n]={false};
        int cnt=0;
        
       for(int j=1;j<s.length();j++)
       {
           
           
           for(int i=0;i<j;i++)
           {
               
               if( ( dp[i+1][j-1]==true || (j-i)<=2) && s[j]==s[i])
               {
                   dp[i][j]=true;
                   cnt++;
               
           }
         }
       }
        return cnt+n;
    }
};
