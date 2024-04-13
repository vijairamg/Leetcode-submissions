class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),0));
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            dp[m-1][i] = (matrix[m-1][i]-'0');
            ans = max(dp[m-1][i],ans);
        }
        
        for(int i = m-2; i >= 0; i--){
            for(int j = 0; j < n; j++){
                dp[i][j] = ((matrix[i][j]-'0') > 0) ? 1 + dp[i+1][j] : 0;
                ans = max(dp[i][j],ans);
            }
        }
        
        
//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 cout<<matrix[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
//         cout<<endl;
        
//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 cout<<dp[i][j]<<" ";
//             }
//             cout<<endl;
//         }
    
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                if(dp[i][j] == 0)
                    continue;
                
                int r = j;
                
                int h = dp[i][j];
                int c = 1;
                
                while(r < n && dp[i][r] != 0){
                    h = min(dp[i][r],h);
                    r+=1;
                    ans = max(h*(r-j),ans);
                }
                
                // cout<<i<<" "<<j<<" "<<h<<" "<<r-j<<endl;
                
                ans = max(h*(r-j),ans);
            }
        }
        
        return ans;
    }
    
};