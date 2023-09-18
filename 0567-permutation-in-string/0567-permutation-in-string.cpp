class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> c1(26,0);
        vector<int> c2(26,0);
        
        for(char c : s1){
            c1[c-'a']+=1;
        }
        
        int l = 0;
        
        for(int r = 0; r < s2.size(); r++){
            
            c2[s2[r]-'a']+=1;    
            
            while((r-l+1) == s1.size()){
                if(c1 == c2){
                    return true;
                }
                c2[s2[l]-'a']-=1;
                l+=1;
            }
        }
        
        return false;
    }
};