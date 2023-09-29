class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        
        bool isIncreasing = true;
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1]){
                isIncreasing = false;
                break;
            }
        }
        
        if(isIncreasing){
            return true;
        }
        
        isIncreasing = true;
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]){
                isIncreasing = false;
                break;
            }
        }
        
        if(isIncreasing){
            return true;
        }
        
        return false;
    }
};