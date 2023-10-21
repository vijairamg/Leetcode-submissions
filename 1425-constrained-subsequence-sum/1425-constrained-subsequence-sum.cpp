class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        
        vector<int> dp(nums.size(),0);
        
        
        deque<pair<int,int>> q;
        dp[0] = nums[0];
        int ans = dp[0];
        q.push_back({nums[0],0});
        
        for(int i = 1; i < nums.size(); i++){
            
            while(!q.empty() && i-q.front().second > k){
                q.pop_front();
            }
            
            dp[i] = nums[i]+max(0,q.front().first);
            
            ans = max(dp[i],ans);
            
            while(!q.empty() && q.back().first < dp[i]){
                q.pop_back();
            }
            
            q.push_back({dp[i],i});
        }
        
        for(int i = 0; i < dp.size(); i++){
            cout<<dp[i]<<endl;
        }
        
        return ans;
    }
};