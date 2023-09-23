class Solution {
public:
    bool canJump(vector<int>& nums) {
        this->nums = nums;
        
        return canJump(0);
    }

private:
    
    unordered_map<int,bool> dp;
    vector<int> nums;
    
    bool canJump(int i){
        if(i >= nums.size()-1){
            return true;
        }
        
        if(dp.find(i) != dp.end()){
            return dp[i];
        }
        
        if(nums[i] == 0){
            dp[i] = false;
            return false;
        }
        
        for(int j = i+nums[i]; j > i ;j--){
            if(canJump(j)){
                dp[i] = true;
                return true;
            }
        }
        
        dp[i] = false;
        return false;
    }
    
};