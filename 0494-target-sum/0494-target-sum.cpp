class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums,target,0,0);    
    }

private:
    
    map<pair<int,int>,int> dp;
    
    int dfs(vector<int>& nums, int target,int i,int total){
        
        if(i == nums.size()){
            if(total == target){
                return 1;
            }else{
                return 0;
            }
        }
        
        if(dp.find({i,total}) != dp.end()){
            return dp[{i,total}];
        }
        
        dp[{i,total}] = dfs(nums,target,i+1,total+nums[i]) + dfs(nums,target,i+1,total-nums[i]);
        
        return dp[{i,total}];
    }
    
    
};