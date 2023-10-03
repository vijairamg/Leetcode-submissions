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
        
        int ans = word1.size()+word2.size();
                
        //same
        if(word1[i] == word2[j]){
            ans = min(ans,dfs(i+1,j+1));
        }
        
        //insert
        ans = min(ans,dfs(i,j+1)+1);
        
        //delete
        ans = min(ans,dfs(i+1,j)+1);
        
        //replace
        ans = min(ans,dfs(i+1,j+1)+1);
        
        dp[{i,j}] = ans;
        return dp[{i,j}];
    }
    
};