class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        unordered_map<int,vector<int>> red;
        for(vector<int> &edge : redEdges){
            red[edge[0]].push_back(edge[1]);
        }
        
        unordered_map<int,vector<int>> blue;
        for(vector<int> &edge : blueEdges){
            blue[edge[0]].push_back(edge[1]);
        }
        
        vector<int> ans(n,-1);
        
        deque<vector<int>> q; //node length color
        
        unordered_set<int> redV;
        unordered_set<int> blueV;
        
        q.push_back({0,0,-1});  
        
        while(!q.empty()){
        
            vector<int> cur = q.front();
            q.pop_front();
            
            int node = cur[0];
            int length = cur[1];
            int color = cur[2];
            
            if(ans[node] == -1){
                ans[node] = length;
            }
            
            if(color != 1){
                for(int nextNode : red[node]){
                    if(redV.find(nextNode) == redV.end()){
                        redV.insert(nextNode);
                        q.push_back({nextNode,length+1,1});
                    }
                }
            }
            
            if(color != 2){
                for(int nextNode : blue[node]){
                    if(blueV.find(nextNode) == blueV.end()){
                        blueV.insert(nextNode);
                        q.push_back({nextNode,length+1,2});
                    }
                }
            }
        }
        
        return ans;
    }
};