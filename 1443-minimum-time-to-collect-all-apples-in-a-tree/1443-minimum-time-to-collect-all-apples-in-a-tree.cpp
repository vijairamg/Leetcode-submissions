class Solution {
public:
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        if(edges.size() == 0){
            return 0;
        }
        
        for(vector<int> edge : edges){
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }    
        this->hasApple = hasApple;
        
        return 2*dfs(0);
    }
    
    private:
    
    unordered_map<int,vector<int>> g;
    unordered_set<int> visited;
    vector<bool> hasApple;
        
    int dfs(int root){
        
        if(visited.find(root) != visited.end()){
            return 0;
        }
        
        visited.insert(root);
        
        if(g.find(root) == g.end()){
            return hasApple[root];
        }
        
        bool isApple = hasApple[root];
        
        int res = 0;
        
        for(int node : g[root]){
            res += dfs(node);
        }
    
        // cout<<root<<" "<<res<<endl;
        
        if(res == 0){
            return isApple && root!=0;
        }
    
        return res + (root != 0 && res>0);
    }
    
};