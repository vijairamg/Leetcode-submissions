class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> prefix(n+1,0);
        
        for(int i = 0; i < n; i++){
            prefix[i+1] = prefix[i] + nums[i]; 
        }
        
        // copy(prefix.begin(),prefix.end(),ostream_iterator<int>(cout," "));
        
        vector<int> res(n,0);
        
        for(int i = 0; i < n; i++){
            res[i] = (nums[i]*i)-prefix[i] + (prefix[n] - prefix[i] - (n-i)*nums[i]);
        }
        
        return res;
    }
};