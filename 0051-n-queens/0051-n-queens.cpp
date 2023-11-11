class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        
        this->n = n;
        
        vector<string> res(n,string(n,'.'));
        
        dfs(0,res);
        
        return sol;
    }
    
private:
    
    unordered_set<int> cols;
    unordered_set<int> pdia;
    unordered_set<int> ndia;
    
    vector<vector<string>> sol;
    
    int n;
    
    void dfs(int i,vector<string> &res){
                
        if(i == n){
            sol.push_back(res);
            return;
        }
        
        for(int j = 0; j < n; j++){
            
            if(cols.find(j) != cols.end() || pdia.find(i+j) != pdia.end() || ndia.find(i-j) != ndia.end())
                continue;
            
            //pick
            
            res[i][j] = 'Q';
            cols.insert(j);
            pdia.insert(i+j);
            ndia.insert(i-j);
            
            dfs(i+1,res);
            
            //unpick
            
            res[i][j] = '.';
            cols.erase(j);
            pdia.erase(i+j);
            ndia.erase(i-j);
        }
    }
    
};