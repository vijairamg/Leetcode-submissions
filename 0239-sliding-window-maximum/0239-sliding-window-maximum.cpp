class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> q;
        vector<int> res;
        
        int l = 0;
        
        for(int r = 0; r < nums.size(); r++){
            
            while(!q.empty() && q.front() < l){
                q.pop_front();
            }

            while(!q.empty() && nums[q.back()] <= nums[r]){
                q.pop_back();
            }
            
            q.push_back(r);
            
            
            if((r-l+1) < k){
                continue;
            }
            
            res.push_back(nums[q.front()]);
            l+=1;
        }
        
        return res;
    }
};