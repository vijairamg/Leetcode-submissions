class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
         dfs(0,questions);
        
        // for(int i = 0; i < questions.size(); i++){
        //     if(dp.find(i) != dp.end()){
        //         cout<<i<<" "<<dp[i]<<endl;
        //     }
        // }
        
        return dp[0];
    }
private:
    
    map<int,long long> dp;
    
    long long dfs(int i,vector<vector<int>>& questions){
        
        if(i >= questions.size()){
            return 0;
        }
        
        if(dp.find(i) != dp.end()){
            return dp[i];
        }
        
        dp[i] = max(questions[i][0]+dfs(questions[i][1]+i+1,questions),dfs(i+1,questions));
        
        return dp[i];
    }
};