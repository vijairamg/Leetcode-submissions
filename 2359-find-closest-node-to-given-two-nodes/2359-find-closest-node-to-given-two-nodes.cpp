class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {

        for(int i = 0; i < edges.size(); i++){
            
            if(edges[i] == -1){
                continue;
            }
            
            adj[i].push_back(edges[i]);
        }
        
        this->n = edges.size();
        
        vector<int> res1 = bfs(node1);
        vector<int> res2 = bfs(node2);
        
//         for(int i = 0; i < n; i++){
//             cout<<res1[i]<<" ";
//         }
//         cout<<endl;
        
//         for(int i = 0; i < n; i++){
//             cout<<res2[i]<<" ";
//         }
//         cout<<endl;
        
        int ans = INT_MAX;
        int ansNode = -1;
        
        for(int i = 0; i < n; i++){
            if(res1[i] != -1 && res2[i] != -1){
                int res = max(res1[i],res2[i]);
                
                if(res < ans){
                    ansNode = i;
                    ans = res;
                }
            }
        }
        
        return ansNode;
    }

private:
    
    unordered_map<int,vector<int>> adj;
    int n;
    
    vector<int> bfs(int node){
        
        vector<int> res(n,-1);
        
        queue<vector<int>> q;
        q.push({node,0});
        
        while(!q.empty()){
            vector<int> cur = q.front();
            q.pop();
            
            int curNode = cur[0];
            int cost = cur[1];
            
            res[curNode] = cost;
            
            for(int next : adj[curNode]){
                if(res[next] == -1){
                    q.push({next,cost+1});
                }
            }
        }
        
        return res;
    }
    
};