class Solution {
public:
    
    
    int find(vector<int>&par, int x){
        if (x != par[x])
            par[x] = find(par,par[x]);
        return par[x];
    }
    
    void uni(vector<int>&par, vector<int>&rank, vector<int>&weight ,int a, int b, int cost){
        
        int parA = find(par,a);
        int parB = find(par,b);
        
        if (rank[parA] < rank[parB])
            par[parA] = parB;
        else{
            par[parB] = parA;
        }
        weight[parA] = weight[parB] = weight[parA] & weight[parB] & cost;
        if (rank[parA] == rank[parB])
            rank[parA]++;
        
    }
    
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        
        vector<int> par(n,0);
        vector<int> rank(n,1);
        vector<int> weight(n,-1);
        
        for(int i = 0; i < n; i++){
            par[i] = i;
        }
        
        for(int i = 0; i < edges.size(); i++){
            uni(par,rank,weight,edges[i][0],edges[i][1],edges[i][2]);
        }
        
 
   
        
        vector<int> ans(query.size(),0);
                
        for(int i = 0; i < query.size(); i++){
            
            int parA = find(par,query[i][0]);
            int parB = find(par,query[i][1]);
            
            if(parA == parB){                
                ans[i] = weight[parA];
            }else{
                ans[i] = -1;   
            }
        }
        
        return ans;
    }
};