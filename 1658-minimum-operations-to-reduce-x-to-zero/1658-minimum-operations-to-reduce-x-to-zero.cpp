class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int l = 0;
        int ans = -1;
        
        int csum = 0;
        
        int sum = accumulate(nums.begin(),nums.end(),0);
        int target = sum - x;
        
        if(target == 0){
            return nums.size();
        }
        
        if(target < 0){
            return -1;
        }
        
        for(int r = 0; r < nums.size(); r++){
            csum += nums[r];
            
            while(csum > target){
                csum -= nums[l];
                l+=1;
            }
            
            if(csum == target){
                ans = max(ans,r-l+1);
            }
        }
        
        if(ans == -1){
            return -1;
        }
        
        return nums.size()-ans;
    }
};