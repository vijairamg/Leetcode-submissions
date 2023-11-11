class Solution {
public:    
    int findKOr(vector<int>& nums, int k) {
       
        map<int,int> count;
        
        for(int num : nums){
            
            int i = 0;
            
            while(num){
                if((num&1) == 1){
                    count[i]+=1;
                }
                num = num >> 1;
                i++;
            }
        }
        
        int res = 0;
        
        for(auto& [i,c] : count){            
            if(c >= k){
                res += pow(2,i);
            }         
        }
        
        return res;
    }
};