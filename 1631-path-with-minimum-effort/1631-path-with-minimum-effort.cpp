class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        
        pq.push({0,0,0});
        dp[0][0] = 0;
        
        vector<int> dX = {0,-1,1,0};
        vector<int> dY = {-1,0,0,1};
        
        while(!pq.empty()){
            
            vector<int> cur = pq.top();
            pq.pop();
            
            int diff = cur[0];
            int x = cur[1];
            int y = cur[2];
            
            // cout<<x<<" "<<y<<endl;
            
            for(int i = 0; i < 4; i++){
             
                int a = x+dX[i];
                int b = y+dY[i];
                
                if(a < 0 || a >= m){
                    continue;
                }
                
                if(b < 0 || b >= n){
                    continue;
                }
                
                int newDiff = max(abs(heights[a][b]-heights[x][y]),diff);
                
                // cout<<a<<" "<<b<<endl;
                
                if(newDiff < dp[a][b]){
                    dp[a][b] = newDiff;
                    pq.push({newDiff,a,b});
                }
            }
        }
        
        // cout<<endl;
        
        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < n; j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return dp[m-1][n-1];
    }
};