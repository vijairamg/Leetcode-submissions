class Solution:
    def maxScore(self, grid: List[List[int]]) -> int:       
        dp = {}
        
        def dfs(i,j,start=False):
            
            if i >= len(grid):
                return 0
            
            if j >= len(grid[0]):
                return 0
            
            if (i,j) in dp and not start:
                return dp[(i,j)]
            
            pos = (i,j)
                        
            cur = grid[i][j]
            
            dp[pos] = 0
            
            if start:
                dp[pos] = float('-inf')
        
            #col 
            for p in range(i+1,len(grid)):
                dp[pos] = max(dp[pos],(grid[p][j]-cur)+dfs(p,j))
                break
            
            #row
            for q in range(j+1,len(grid[0])):
                dp[pos] = max(dp[pos],(grid[i][q]-cur)+dfs(i,q))
                break
                   
            return dp[pos]
        
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                dfs(i,j,True)
                
        
        return max(dp.values())