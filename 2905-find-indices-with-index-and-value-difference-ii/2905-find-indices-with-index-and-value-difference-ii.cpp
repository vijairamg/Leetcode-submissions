class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        
        if(nums.size() <= indexDifference){
            return {-1,-1};
        }
        
        if(nums.size() == 1){
            
            if(valueDifference == 0)
                return {0,0};
            
            return {-1,-1};
        }
        
        int n = nums.size();
        
        vector<int> maxSoFar(n);
        vector<int> minSoFar(n);
        
        maxSoFar[n-1] = nums[n-1];
        minSoFar[n-1] = nums[n-1];
        
        for(int i = n-2; i>=0; i--){
            maxSoFar[i] = max(maxSoFar[i+1],nums[i]);
            minSoFar[i] = min(minSoFar[i+1],nums[i]);
        }
        
        // copy(maxSoFar.begin(),maxSoFar.end(),ostream_iterator<int>(std::cout," "));
        // cout<<endl;
        // copy(minSoFar.begin(),minSoFar.end(),ostream_iterator<int>(std::cout," "));
        // cout<<endl;
        
        for(int i = 0; i < nums.size()-indexDifference; i++){
            if(abs(maxSoFar[i+indexDifference]-nums[i]) >= valueDifference){
                int j = i+indexDifference;
                                
                for( ;j < n && maxSoFar[j] >= maxSoFar[i+indexDifference]; j++);
                return {i,j-1};
            }
                
            if(abs(minSoFar[i+indexDifference]-nums[i]) >= valueDifference){
                int j = i+indexDifference;
                                
                for( ;j < n && minSoFar[j] <= minSoFar[i+indexDifference]; j++);
                return {i,j-1};
            }
        }
        
        return {-1,-1};
    }
};