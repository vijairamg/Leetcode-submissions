class Solution {
public:
    int minDistance(string word1, string word2) {
        this->word1 = word1;
        this->word2 = word2;
        
        return dfs(0,0);
    }

private:
    
    string word1;
    string word2;
    map<pair<int,int>,int> dp;
    
    int dfs(int i, int j){
        if(i == word1.size()){
            return j == word2.size() ? 0 : word2.size()-j;
        }
        
        if(j == word2.size()){
            return word1.size()-i;
        }
        
        if(dp.find({i,j}) != dp.end()){
            return dp[{i,j}];
        }
        
        int ans = INT_MAX;
                
        //same
        if(word1[i] == word2[j]){
            ans = min(ans,dfs(i+1,j+1));
        }
        
        //insert
        int ins = dfs(i,j+1);
        ins = ins != INT_MAX ? ins+1 : ins;
        ans = min(ans,ins);
        
        //delete
        int del = dfs(i+1,j);
        del = del != INT_MAX ? del+1 : del;
        ans = min(ans,del);
        
        //replace
        int rel = dfs(i+1,j+1);
        rel = rel != INT_MAX ? rel+1 : rel;
        ans = min(ans,rel);
        
        dp[{i,j}] = ans;
        return dp[{i,j}];
    }
    
};