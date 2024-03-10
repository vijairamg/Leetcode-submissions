class Solution {
public:    
    int minimumLength(string s) {
        
        cout<<s<<endl;
        
        if(s.size() <= 1){
            return s.size();
        }
        
        int l = 0;
        int r = s.size()-1;
      
        while(l < r && s[l] == s[r]){
            
            char c = s[l];
            
            while(s[l] == c && l <= r){
                l+=1;
            }
            
            while(s[r] == c && l <= r){
                r -=1;
            }
            
        }
        
        return r -l + 1;
    }
};