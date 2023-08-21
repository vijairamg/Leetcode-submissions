class Solution {
public:
    bool isPossible(string c , string s){
        string res = "";
        
        while(res.size() <= s.size()){
            res += c;
            if(res == s){
                return true;
            }
        }
        
        return false;
    }
    
    bool repeatedSubstringPattern(string s) {
        
        string c = "";
        
        for(int i = 0; i < s.size()-1; i++){
            c+=s[i];
            if(isPossible(c,s)){
                return true;
            }
        }
        
        return false;
    }
};