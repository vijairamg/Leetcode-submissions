class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size() != s3.size()){
            return false;
        }
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        
        return dfs(0,0);
    }
    
    private:
    
    map<pair<int,int>,bool> dp;
    string s1;
    string s2;
    string s3;
    
    bool dfs(int i, int j){
        if(i+j == s3.size()){
            return true;
        }
        
        if(dp.find({i,j}) != dp.end()){
            return dp[{i,j}];
        }
        
        dp[{i,j}] = false;
        
        if(s1[i] == s3[i+j]){
            dp[{i,j}] = dfs(i+1,j);
        }
        
        if(s2[j] == s3[i+j]){
            dp[{i,j}] = dp[{i,j}] || dfs(i,j+1);
        }
         
        return dp[{i,j}];
    }
};