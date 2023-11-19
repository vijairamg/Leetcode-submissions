class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        this->colors = colors;
        
        N = colors.size();
        for(const vector<int> edge: edges){
            adj[edge[0]].push_back(edge[1]);
        }
        
        count.resize(N,vector<int>(26,0));
        
        int res = 0;
        
        for(int i = 0; i < N; i++){
            res = max(res,dfs(i));
        }
        
        return res == INT_MAX ? -1 : res;
    }

private:
    string colors;
    unordered_map<int,vector<int>> adj;
    int N;
    vector<vector<int>> count;
    unordered_set<int> visited;
    unordered_set<int> path;
    
    int dfs(int node){
        if(path.find(node) != path.end()){
            return INT_MAX;
        }
        
        if(visited.find(node) != visited.end()){
            return 0;
        }
        
        visited.insert(node);
        path.insert(node);
        
        int colorIndex = colors[node]-'a';
        
        for(int nextNode : adj[node]){
            if(dfs(nextNode) == INT_MAX){
                return INT_MAX;
            }
            
            for(int i = 0; i < 26; i++){
                count[node][i] = max(count[node][i],count[nextNode][i]);
            }
        }
        
        count[node][colorIndex]+=1;
        
        path.erase(node);
        
        return *max_element(count[node].begin(),count[node].end());
    }
};