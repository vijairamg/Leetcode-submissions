class Solution {
public:
    int maxLength(vector<string>& arr) {        
        for(string word : arr){            
            int mask = 0;
            
            bool flag = true;
            
            for(char l : word){
                if((mask >> (l-'a') ) & 1 ){
                    flag = false;
                    break;
                }
                
                mask = mask | (1 << (l-'a'));
            }
            
            if(!flag){
                continue;
            }
            
            this->arr.push_back(word);
            masks.push_back(mask);
        }
        
        
        return dfs(0,0);
    }
private:
    vector<int> masks;
    vector<string> arr;
    
    bool isConflict(int a,int b){
        while(a){
            int m1 = a&1;
            int m2 = b&1;
        
            if(m1 == 1 && m2 == 1){
                return true;
            }
            
            a = a >> 1;
            b = b >> 1;
        }
        
        return false;
    }
    
    int dfs(int i,int mask){
        if(i == masks.size()){
            return 0;   
        }
        
        int ans = 0;
        
        if(!isConflict(mask,masks[i])){
           int newMask = mask | masks[i];
           ans = arr[i].size() + dfs(i+1,newMask); 
        }
        
        return max(ans,dfs(i+1,mask));
    }
};