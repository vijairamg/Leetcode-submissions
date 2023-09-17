class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        if(s.size() >= t.size()){
            return s == t;
        }
        
        int i = 0;
        int j = 0;
        
        int n = s.size();
        int m = t.size();
        
        while(i < n && j < m){
            if(s[i] == t[j]){
                i+=1;
            }
            j+=1;
        }
            
        return i == n;
    }
};