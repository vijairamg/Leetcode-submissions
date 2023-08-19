class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        unordered_set<int> visited;
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        pq.emplace(0,0);
        int res = 0;
        
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            int cur_node = cur.second;
            int cur_weight = cur.first;
            
            if(visited.find(cur_node)!=visited.end()){
                continue;
            }
            
            visited.insert(cur_node);
            res += cur_weight;
            
            for(int i = 0; i < points.size(); i++){
              if(cur_node == i){
                  continue;
              }   
                
              pq.emplace(abs(points[cur_node][0]-points[i][0])+abs(points[cur_node][1]-points[i][1]),i);
            }
        }
        
        return res; 
    }
};