class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> res(ratings.size(),1);
        
        int n = ratings.size();
    
        for(int i = 0; i < ratings.size()-1; i++){   
            if(ratings[i] < ratings[i+1]){
                res[i+1] = res[i]+1;
            }
        }
        
        for(int i = n-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]){
                res[i] = max(res[i],res[i+1]+1);
            }
        }
        
        return accumulate(res.begin(),res.end(),0);
    }
};