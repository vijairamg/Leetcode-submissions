class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        
        this->seats = seats;
        
        for(int i = 0; i < roads.size(); i++){
            edges[roads[i][0]].push_back(roads[i][1]);
            edges[roads[i][1]].push_back(roads[i][0]);
        }
        
        dfs(0,-1);
        
        return res;
    }

private:
    
    long long res;
    map<int,vector<int>> edges;
    int seats;
    
    int dfs(int cur, int parent){
        int passengers = 0;
        
        for(int node : edges[cur]){
            if(node != parent){
                int p = dfs(node,cur);
                res += ceil((double)p/seats);
                passengers+=p;
            }
        }
        
        return passengers+1;
    }
    
};