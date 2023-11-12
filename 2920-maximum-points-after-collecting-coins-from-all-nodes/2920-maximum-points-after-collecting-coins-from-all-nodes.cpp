class Solution {
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        
        for(const auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        memset(memo, -1, sizeof(memo));
        
        this->coins = coins;
        this->k = k;
        
        int res = dfs(0);
        

        return res;
    }
    
    
    
private:
    unordered_map<int,vector<int>> adj;
    unordered_map<string,int> dp;
    
    int memo[100001][14];
       
    
    vector<int> coins;
    int k;
    
    string gk(int node,int prev){
        return to_string(node)+"_"+to_string(prev);
    }
    
    int dfs(int node,int prev = 0,int dnd = -1){
        int res = 0;
        int resF = 0;
        
        string key = gk(node,prev);
        
        if(prev >= 14){
            dp[key] = 0;
            return 0;
        }
            
        if(memo[node][prev] != -1){
            return memo[node][prev];
        }
        
        for(auto next : adj[node]){
            if(next == dnd)
                continue;
            res += dfs(next,prev,node);
            resF += dfs(next,prev+1,node);
        }
        
        int cur = coins[node] >> prev;
        
        memo[node][prev] = max(res+(cur-k),resF+(cur >> 1));
                
        return memo[node][prev];
    }
};