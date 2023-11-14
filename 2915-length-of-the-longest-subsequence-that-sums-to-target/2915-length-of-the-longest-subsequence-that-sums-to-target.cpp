class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        this->N = nums.size();
        this->nums = nums;
        
        memset(dp,-1,sizeof(dp));
        
        int ans = dfs(0,target);
        
//         for(const auto& [key,value] : dp){
//             const auto& [pos,t] = key;
            
//             cout<<pos<<" "<<t<<" "<<value<<endl;
//         }
        
        return ans >= 0 ? ans : -1;
    }
    
private:
    
    int N;
    vector<int> nums;
    
    int dp[1001][1001];
    
    int dfs(int pos, int t){
        
        // cout<<pos<<" "<<t<<endl;
        
        if(t == 0){
            return 0;
        }
        
        if(pos == N){
            return INT_MIN;
        }
        
        if(dp[pos][t] != -1){
            return dp[pos][t];
        }
        
        int res = INT_MIN;
        
        if(nums[pos] <= t){
            res = max(1+dfs(pos+1,t-nums[pos]),dfs(pos+1,t));
        }else{
            res = dfs(pos+1,t);
        }
        
        dp[pos][t] = res;
        
        return res;
    }
    
};