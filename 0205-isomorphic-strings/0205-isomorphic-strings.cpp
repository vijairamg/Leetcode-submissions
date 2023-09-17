class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char,char> dp;
        unordered_set<char> used;
        
        for(int i = 0; i < s.size(); i++){
            
            if(dp.find(s[i]) != dp.end()){
                if(dp[s[i]] != t[i]){
                    return false;
                }
            }else{
                
                if(used.find(t[i]) != used.end()){
                    return false;
                }

                dp[s[i]] = t[i];
                used.insert(t[i]);
            }
            
        }
        
        return true;
    }
};