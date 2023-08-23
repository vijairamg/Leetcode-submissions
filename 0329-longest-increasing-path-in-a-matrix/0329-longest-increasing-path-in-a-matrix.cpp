class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = -1;
        
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                int temp = dfs(i,j,matrix);
                // cout<<i<<" "<<j<<" "<<temp<<endl;
                res = max(res,temp);
            }
        }
        
        return res;
    }
    
    private:
    
    map<pair<int,int>,int> dp;
    
    int dfs(int i, int j,vector<vector<int>>& matrix){
        
        if(dp.find({i,j})!=dp.end()){
            return dp[{i,j}];
        }
        
        dp[{i,j}] = 1;
        
        
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        
        for(int a = 0; a < 4; a++){
            int x = i+dx[a];
            int y = j+dy[a];
            
            if(x < 0 || x >= matrix.size()){
                continue;
            }

            if(y < 0 || y >= matrix[x].size()){
                continue;
            }
            
            if(matrix[i][j] >= matrix[x][y]){
                continue;
            }
            
            dp[{i,j}] = max(dp[{i,j}],1+dfs(x,y,matrix));
        }
        
        return dp[{i,j}];
    }
};