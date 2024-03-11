class Solution {
public:
    string customSortString(string order, string s) {
        
        unordered_map<char,int> count;
        
        for(char c : s){
            count[c]+=1;
        }
        
        string res = "";
        
        for(char c : order){
            auto it = count.find(c);
            
            if(it != count.end()){
                
                // cout<<c<<" "<<count[c]<<endl;
                // cout<<string(count[c],c)<<endl;
                res += string(count[c],c);
                count.erase(it);
            }
        }
        
        for(auto it = count.begin(); it != count.end(); it++){
            char c = it->first;
            int n = it->second;
            
            res += string(n,c);
        }
        
        return res;
    }
};