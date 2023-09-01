class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        //Remove negatives
        for(int i = 0; i < nums.size(); i++){
            nums[i] = max(nums[i],0);
        }
        
        for(int i = 0; i < nums.size(); i++){
            int index = abs(nums[i])-1;
            
            if(index < 0 or index >= nums.size()){
                continue;
            }
            
            if(nums[index] == 0){
                nums[index] = -(index+1);
            }else{
                nums[index] = -(abs(nums[index]));
            }            
        }
        
        for(int i = 1; i <= nums.size(); i++){
            int index = i-1;
            if(nums[index] >= 0){
                return i;
            }
        }
        
        return nums.size()+1;
    }
};