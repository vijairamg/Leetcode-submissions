class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int l = 0;
        int r = nums.size()-1;
        
        while(l < r){
            while(r > 0 && nums[r] % 2 == 1)
                r-=1;
            
            if(l > r){
                return nums;
            }
            
            if(nums[l]%2 == 1){
                int temp = nums[l];
                nums[l] = nums[r];
                nums[r] = temp;
                r-=1;
            }
            
            l+=1;
        }
        
        return nums;
    }
};