class Solution {
public:
    int numDistinct(string s, string t) {
        
        this->s = s;
        this->t = t;
        
        return dfs(0,0);
    }
    
private: 
    map<pair<int,int>,int> dp;
    
    string s;
    string t;
    
    int dfs(int i, int j){
    
        if(j == t.size()){
            return 1;
        }
        
        if(i == s.size()){
            return 0;
        }
            
        if(dp.find({i,j}) != dp.end()){
            return dp[{i,j}];
        }
        
        int res = -1;
        
        if(s[i] == t[j]){
            res = dfs(i+1,j+1)+dfs(i+1,j);
        }else{
            res = dfs(i+1,j);
        }
        
        dp[{i,j}] = res;
        return dp[{i,j}];
    }
    
};