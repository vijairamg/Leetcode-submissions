class Solution {
public:
    int getOperations(vector<int>& nums1, vector<int>& nums2){
        
        int n = nums1.size(); 
        
        int count = 0;
        
        for(int i = 0; i < nums1.size(); i++){
            
            if(nums1[i] <= nums1[n-1] && nums2[i] <= nums2[n-1])
                continue;
            
            if(max(nums1[i],nums2[i]) > max(nums1[n-1],nums2[n-1]))
                return n+1;
            
            if(nums1[i] > nums2[n-1] || nums2[i] > nums1[n-1])
                return n+1;
            
            count += 1;
        }
        
        return count;
    }
    
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        
        int a = max_element(nums1.begin(),nums1.end()) - nums1.begin();
        int b = max_element(nums2.begin(),nums2.end()) - nums2.begin();
                
        if(nums1[n-1] >= nums1[a] && nums2[n-1] >= nums2[b])
            return 0;
        
        if(min(nums1[a],nums2[a]) > max(nums1[n-1],nums2[n-1]))
            return -1;
        
        if(min(nums1[b],nums2[b]) > max(nums1[n-1],nums2[n-1]))
            return -1;
        
        int ans = getOperations(nums1,nums2);
        
        int temp = nums1[n-1];
        nums1[n-1] = nums2[n-1];
        nums2[n-1] = temp;
        
        ans = min(ans,1+getOperations(nums1,nums2));
        
        if(ans >= n){
            return -1;
        }
        
        return ans;
    }
};