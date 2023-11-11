
class Solution {
public:
    using ll = long long;
    
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        
        ll sum1 = accumulate(begin(nums1),end(nums1),0LL);
        ll sum2 = accumulate(begin(nums2),end(nums2),0LL);
        
        auto ifZero = [](int i){
            return i == 0;
        };
        
        
        
        int z1 = count_if(begin(nums1),end(nums1),ifZero);
        int z2 = count_if(begin(nums2),end(nums2),ifZero);
       
        ll diff = abs(sum1-sum2);
        
        if(z1 == 0 && sum1 < sum2 + z2)
            return -1;
        
        if(z2 == 0 && sum2 < sum1+ z1)
            return -1;
        
        return max(z1+sum1,z2+sum2);
    }
};