typedef pair<double, int> pi;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& times, vector<double>& succProb, int start_node, int end_node) {
        vector<double> dp(n,-1);
                
        map<int,vector<pair<int,double>>> edges;
        
        for(int i = 0; i < times.size(); i++){
            edges[times[i][0]].push_back({times[i][1],succProb[i]});
            edges[times[i][1]].push_back({times[i][0],succProb[i]});
        }
        
        priority_queue<pi, vector<pi>> q;
        
        q.push({1,start_node});
        
        while(!q.empty()){            
            auto cur = q.top();
            q.pop();
            int node = cur.second;
                     
            if(dp[node] != -1){
                continue;
            }
            
            dp[node] = cur.first;
            // cout<<node<<" "<<cur.first<<endl;
            
            for(int i = 0; i < edges[node].size(); i++){
                if(dp[edges[node][i].first] == -1){
                    q.push({edges[node][i].second*cur.first,edges[node][i].first});
                }
            }
                        
        }
        
        return dp[end_node] == -1 ? 0 : dp[end_node];
    }
};