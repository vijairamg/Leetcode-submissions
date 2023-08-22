class Solution {
public:

    int N;
    int target;
    int sum;
    
    int dfs(int i,int total,vector<vector<int>> &dp,vector<int>& stones){
         if(total >= target || i == N){
             return abs(total-(sum-total));
         }   
        
         if(dp[i][total] != -1){
             return dp[i][total];
         }
        
        dp[i][total] = min(dfs(i+1,total,dp,stones),dfs(i+1,total+stones[i],dp,stones));
        
        return dp[i][total];
    }

    int lastStoneWeightII(vector<int>& stones) {
        N = stones.size();
        
        sum = accumulate(stones.begin(), stones.end(), 0);
        vector<vector<int>> dp(N,vector<int>(sum+1,-1));
        
        target = ceil(sum/2);
        
        return dfs(0,0,dp,stones);
    }
};