class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        this->piles = piles;
        
        this->dp = vector<vector<int>>(piles.size(),vector<int>(k+1,-1));
        
        return dfs(0,k);
    }

private:
    vector<vector<int>> piles;
    vector<vector<int>> dp;
    
    int dfs(int i, int coins){
        
        if(i == piles.size()){
            return 0;
        }
        
        if(dp[i][coins] != -1){
            return dp[i][coins];
        } 
        
        dp[i][coins] = dfs(i+1,coins);
        
        int cp = 0;
        
        for(int j = 0; j < min(coins,(int)piles[i].size()); j++){
            cp += piles[i][j];
            dp[i][coins] = max(dp[i][coins],cp+dfs(i+1,coins-j-1));
        }
        
        return dp[i][coins];
    }
};