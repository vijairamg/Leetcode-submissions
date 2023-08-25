typedef pair<int, int> pi;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& times, int src, int dst, int k) {
        
        map<int,vector<pair<int,int>>> edges;
        for(int i = 0; i < times.size(); i++){
            edges[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        
        vector<int> dp(n,INT_MAX);
        
        int steps = 0;
        
        priority_queue<pi,vector<pi>,greater<pi>> q;
        q.push({0,src});
        
        while(steps <= k+1){
            
            priority_queue<pi,vector<pi>,greater<pi>> new_q;
            
            while(!q.empty()){
                auto cur = q.top();
                q.pop();
                
                int node = cur.second;
                int cost = cur.first;
                
                if(cost < dp[node]){
                    dp[node] = cost;
                    
                   for(int i = 0; i < edges[node].size(); i++){
                        new_q.push({edges[node][i].second+cost,edges[node][i].first});
                    }
                }            
            }
            
            q = new_q;
            steps++;
        }
              
        return dp[dst] == INT_MAX ? -1 : dp[dst];
    }
};