class Solution {
public:
    
    unordered_map<int,int> dp;
    
    int dfs(int mask,int op,vector<int> &nums){
        
        if(dp.find(mask) != dp.end()){
            return dp[mask];
        }
        
        if(2*op > nums.size()){
            return 0;
        }
        
        dp[mask] = 0;
        
        for(int i = 0; i < nums.size(); i++){
            
            if((mask>>i) & 1 == 1){
                    continue;
            }
            
            for(int j = i + 1; j < nums.size(); j++){
                
                if((mask>>j)&1 == 1){
                    continue;
                }    
                
                int newmask = mask + (1 << i) + (1 << j);
                       
                dp[mask] = max(dp[mask],(op*__gcd(nums[i],nums[j]))+dfs(newmask,op+1,nums));
                                
            }
        }
        
        return dp[mask];
    }
    
    int maxScore(vector<int>& nums) {
        return dfs(0,1,nums);
    }
};