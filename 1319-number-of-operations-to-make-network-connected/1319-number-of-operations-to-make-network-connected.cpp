class Solution {
public:
        
    int find(int node,vector<int>&par){
        int res = node;
        
        while(res != par[res]){
            par[res] = par[par[res]];
            res = par[res];
        }
        return res;
    }
    
    int uni(int n1 , int n2 , vector<int> & par , vector<int> &rank){
     
        int par1 = find(n1,par);
        int par2 = find(n2,par);
        
        if(par1 == par2){
            return 0;
        }
        
        if(rank[par1] >= rank[par2]){
            rank[par1] += rank[par2];
            par[par2] = par1;
        }else{
            rank[par2] += rank[par1];
            par[par1] = par2;
        }
        
        return 1;
    }
    
    
    int makeConnected(int n, vector<vector<int>>& isConnected) {

        vector<int> par;
        vector<int> rank(n,1);
        
        for(int i = 0; i < n; i++){
            par.push_back(i);
        }
        
        int res = 0;
        
        for(int i = 0; i < isConnected.size(); i++){
            res+= uni(isConnected[i][0],isConnected[i][1],par,rank);            
        }
        
        int excess = isConnected.size() - res; 
        
        
        // for(int i = 0; i < n; i++){
        //     cout<<find(i,par)<<endl;
        // }
        
        unordered_set<int> unipar;
        
        for(int i = 0; i < n; i++){
            unipar.insert(find(i,par));
        }
        
        int diff = unipar.size()-1;
        
        cout<<diff<<" "<<excess<<endl;
        
        return diff <= excess ? diff : -1;
    }
};