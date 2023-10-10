class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int j = 0;
        int N = nums.size();
        int ans = N;
        
        nums.erase(unique(begin(nums),end(nums)),end(nums));
                
        for(int i = 0; i < nums.size(); i++){
            while(j < nums.size() && nums[i]+N-1 >= nums[j]){
                j++;
            }
            ans = min(ans,N-j+i);
        }
        
        return ans;
    }
};