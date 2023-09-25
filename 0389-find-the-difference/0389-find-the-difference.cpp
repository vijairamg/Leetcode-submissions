class Solution {
public:
    char findTheDifference(string s, string t) {
        
        vector<int> count(26,0);
        
        for(char c : s){
            count[c-'a']+=1;
        }
        
        for(char c : t){
            count[c-'a']-=1;
        }
        
        for(int i = 0; i < 26; i++){
            if(count[i] < 0){
                char r = 'a' + i;
                return r;
            }
        }
        
        return 'a';
    }
};