class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        if(amount <= 0){
            return 0;
        }
        
        vector<int> dp(amount+1,INT_MAX);
        dp[0] = 0;
        
        for(int i = 1; i <= amount; i++){
            for(int coin : coins){
                if(coin <= i){
                    
                    if(dp[i-coin] == INT_MAX){
                        continue;
                    }
                    
                    // cout<<dp[i-coin]<<" "<<i<<" "<<coin<<endl;
                    dp[i] = min(dp[i-coin]+1,dp[i]);            
                }
            }
        }
        
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};