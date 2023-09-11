class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
        unordered_map<int,vector<int>> dp;
        
        for(int i = 0; i < groupSizes.size(); i++){
            dp[groupSizes[i]].push_back(i);
        }
        
        vector<vector<int>> res;
        
        for(auto it : dp){
            int size = it.first;
            vector<int> cand = it.second;
            
            for(int i = 0; i < cand.size(); i+=size){
                vector<int> temp(cand.begin()+i,cand.begin()+i+size);
                res.push_back(temp);
            }
        }
        
        return res;
    }
};