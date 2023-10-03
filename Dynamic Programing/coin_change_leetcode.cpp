class Solution {
public:
    const int N=1e4;
    int dp[10010];
    int func(vector<int> coins,int amount)
    {
        if(amount==0) return dp[amount]=0;
        int ans=INT_MAX;
        if(dp[amount]!=-1) return dp[amount];
        
        for(int coin: coins){
            if(amount-coin>=0)
            ans=min(ans+0ll ,func(coins,amount-coin)+1ll);
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        
        int ans=func(coins,amount);
        return ans==INT_MAX ? -1: ans;
    }
};
