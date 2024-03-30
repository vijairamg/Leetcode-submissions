class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k) - atMost(nums,k-1);   
    }
    
    int atMost(vector<int>& nums, int k){
        
        unordered_map<int,int> seen;
        
        int l = 0;
        int count = 0;
        
        for(int r = 0; r < nums.size(); r++){
            
            seen[nums[r]]+=1;
            
            while(seen.size() > k){
                seen[nums[l]]-=1;
                
                if(seen[nums[l]] == 0){
                    seen.erase(nums[l]);
                }
                
                l+=1;
            }
        
            count += r-l+1;
        }
        
        return count;
    }
};