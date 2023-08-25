typedef pair<int, int> pi;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dp(n+1,INT_MAX);
        
        dp[0] = -1;
        
        map<int,vector<pair<int,int>>> edges;
        
        for(int i = 0; i < times.size(); i++){
            edges[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        
        priority_queue<pi, vector<pi>, greater<pi> > q;
        
        q.push({0,k});
        
        while(!q.empty()){            
            auto cur = q.top();
            q.pop();
            int node = cur.second;
            
            // cout<<node<<" "<<cur.first<<endl;
                        
            if(dp[node] != INT_MAX){
                continue;
            }
            
            dp[node] = cur.first;
            
            for(int i = 0; i < edges[node].size(); i++){
                if(dp[edges[node][i].first] == INT_MAX){
                    q.push({edges[node][i].second+cur.first,edges[node][i].first});
                }
            }
                        
        }
        
        
        int res = *max_element(dp.begin(),dp.end());
        return  res == INT_MAX ? -1 : res;
    }
};