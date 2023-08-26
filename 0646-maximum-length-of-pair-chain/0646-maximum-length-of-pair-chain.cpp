bool Compare(vector<int>&a , vector<int>&b){
            return b[1] > a[1];
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),Compare);
        
        vector<vector<int>> res;
        
        res.push_back(pairs[0]);
        
        for(int i = 1; i < pairs.size(); i++){
            if(pairs[i][0] > res.back()[1]){
                res.push_back(pairs[i]);
            }
        }
        
        return res.size();
    }
};