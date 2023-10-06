class Solution {
public:
    int integerBreak(int n) {
        int dp[n+1];
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++){
            dp[i] = (i == n) ? 0 : i;
            
            for(int j = 1; j < i; j++){
                dp[i] = max(dp[i],j*dp[i-j]);   
            }
        }
        
        return dp[n];
    }
};