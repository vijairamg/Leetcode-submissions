class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n,1);
        
        pre[0] = nums[0];
        for(int i = 1; i < n; i++){
            pre[i] = nums[i] * pre[i-1];
        }
        
        vector<int> post(n,1);
        
        post[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            post[i] = post[i+1]*nums[i];
        }
        
        vector<int> ans(n,1);
        ans[0] = post[1];
        
        for(int i = 1; i < n-1; i++){
            ans[i] = pre[i-1]*post[i+1];
        }
        
        ans[n-1] = pre[n-2];
        
        return ans;
    }
};