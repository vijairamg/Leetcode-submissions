class Solution {
    
private:
    unordered_map<int,unordered_map<int,vector<int>>> atm;
    set<int> times;
    unordered_set<int> hasSecret;
    unordered_set<int> visited;

    void dfs(int src, unordered_map<int,vector<int>> &adj){
        
        if(visited.find(src) != visited.end()){
            return; 
        }
        
        hasSecret.insert(src);
        visited.insert(src);
        
        for(int next : adj[src]){
            dfs(next,adj);
        }
    }
    
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        hasSecret.insert(0);
        hasSecret.insert(firstPerson);
                        
        for(vector<int>& meet : meetings){
            atm[meet[2]][meet[0]].push_back(meet[1]);
            atm[meet[2]][meet[1]].push_back(meet[0]);
            
            times.insert(meet[2]);
        }
        
        for(auto it = times.begin(); it != times.end(); it++){
            
            int t = *it;
            
            // cout<<t<<endl;
            
            for(auto it1 = atm[t].begin(); it1 != atm[t].end(); it1++){
                
                int key = it1->first;                
                
                if(hasSecret.find(key) != hasSecret.end()){
                    dfs(key,atm[t]);
                }
            
            }
            
            visited.clear();
        }
        
        vector<int> res;
        res.insert(res.end(),hasSecret.begin(),hasSecret.end());
        
        return res;
    }
    
};