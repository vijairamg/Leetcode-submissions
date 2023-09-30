class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        if(nums.size() <= 2){
            return false;
        }
        
        for(int i = 0; i < nums.size()-2; i++){
            
            if(i > 0 && nums[i] >= nums[i-1]){
                continue;
            }
            
            for(int j = i+1; j < nums.size()-1;j++){
                
                if(nums[j] <= nums[i]){
                    break;
                }
                
                for(int k = j+1; k < nums.size(); k++){
                    
                    if(nums[k] >= nums[j]){
                        break;
                    }
                    
                    if(nums[i] < nums[k] && nums[k] < nums[j]){
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};