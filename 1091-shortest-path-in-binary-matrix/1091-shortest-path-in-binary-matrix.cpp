class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid[0].size();
        
        if(grid[0][0] + grid[n-1][n-1] != 0){
            return -1;
        }
        
        deque<vector<int>> q;
        
        q.push_back({0,0,1}); //x y l
        
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        
        vector<int> xD = {0,0,1,-1,1,-1,1,-1};
        vector<int> yD = {1,-1,0,0,1,-1,-1,1};
        
        while(!q.empty()){
            vector<int> cur = q.front();
            q.pop_front();
            
            int x = cur[0];
            int y = cur[1];
            int l = cur[2];
            
            // cout<<x<<" "<<y<<" "<<l<<endl;
            
            if(x == n-1 && y == n-1){
                return l;
            }
            
            for(int i = 0; i < 8; i++){
                int a = x+xD[i];
                int b = y+yD[i];
                
                if(a < 0 || a >= n){
                    continue;
                }
                
                if(b < 0 || b >= n){
                    continue;
                }
                
                if(visited[a][b]){
                    continue;
                }
                
                if(grid[a][b]){
                    continue;
                }
                
                visited[a][b] = true;
                
                q.push_back({a,b,l+1});
            }
        }
        
        return -1;
    }
};