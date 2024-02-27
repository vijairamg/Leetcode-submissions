class UnionFind{
 
    public:
    int count;
 
    vector<int> par;
    vector<int> rank;
    
    UnionFind(int n){
        
        count = n;
        
        par.resize(n);
        rank.resize(n);
        
        for(int i = 0; i < n; i++){
            par[i] = i;
            rank[i] = 1;
        }
    }
    
    int find(int node){
            
        while(node != par[node]){
            par[node] = par[par[node]];
            node = par[node];
        }
        
        return node;
    }
    
    void uni(int nodeA, int nodeB){
        
        int parA = find(nodeA);
        int parB = find(nodeB);
        
        if(parA != parB){
            
            if(rank[parA] > rank[parB]){
                par[parB] = parA;
                rank[parA] += rank[parB];
            }else{
                par[parA] = parB;
                rank[parB] += rank[parA];
            }
            
            count-=1;
        }
    }

};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        
        UnionFind uf(nums.size());
                
        unordered_map<int,int> factor_map;
        unordered_set<int> visited;
        
        for(int i = 0; i < nums.size(); i++){
            
            int num = nums[i];
            int f = 2;
            
            if(nums[i] > 1 && visited.find(nums[i]) != visited.end()){
                uf.count -= 1;
                continue;
            }
                    
            while(f*f <= num){
                
                if(num % f == 0){
                    
                    if(factor_map.find(f) != factor_map.end()){                        
                        uf.uni(factor_map[f],i);
                    }else{
                        factor_map[f] = i;
                    }
                    
                    
                    while(num % f == 0){
                        num /= f;                    
                    } 
                }
                
                f+=1;
            }
            
            if(num > 1){
                if(factor_map.find(num) != factor_map.end()){                        
                    uf.uni(factor_map[num],i);
                }else{
                    factor_map[num] = i;
                }
            }
            
            visited.insert(nums[i]);
            
        }
        
        return uf.count == 1;
    }
};