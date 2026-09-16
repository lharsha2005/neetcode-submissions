class Solution {
public:
    int dfs(vector<int>& dp, vector<int>& coins, int amount){
        if(amount==0){
            return 0;
        }
        if(dp[amount]!=-1)  return dp[amount];
        
        int ans=INT_MAX;
        for(int coin:coins){
            if((amount-coin)>=0){
                int temp=dfs(dp,coins,amount-coin);
                if (temp != INT_MAX) {
                    ans = min(ans, 1 + temp);
                }
            }
        }
        dp[amount]=ans;
        return ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int ans=dfs(dp,coins,amount);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};
