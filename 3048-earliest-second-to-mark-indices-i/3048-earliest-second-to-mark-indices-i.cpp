class Solution {
public:
    
    bool isPossible(vector<int>& nums, vector<int>& changeIndices, int idx){
        
        unordered_map<int,int> lastIndex;
        
        for(int i = 0; i < idx; i++){
            lastIndex[changeIndices[i]] = i;
        }
        
        if(lastIndex.size() != nums.size()){
            return false;
        }
        
        int count = 0;
        
        for(int i = 0; i < idx; i++){
            if(i == lastIndex[changeIndices[i]]){
                if(count < nums[changeIndices[i]-1]){
                    return false;
                }else{
                    count -= nums[changeIndices[i]-1];
                }
            }else{
                count+=1;
            }
        }
        
        return true;
    }
    
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
      int n = nums.size(), m = changeIndices.size();
        int l = 0, r = m + 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (isPossible(nums, changeIndices, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r == m + 1? -1 : r;
    }
};