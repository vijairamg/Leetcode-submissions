class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char,int> right;
        unordered_set<string> res;
        unordered_set<char> left;
        
        for(int i = 0; i < s.size(); i++){
            right[s[i]]+=1;
        }
                
        for(int i = 0; i < s.size(); i++){
            right[s[i]]-=1;
            
            for(int j = 0; j < 26; j++){
                char c = 'a'+j;
                if(left.find(c) != left.end() && right[c] > 0){
                    string temp = "";
                    temp+=s[i];
                    temp+=c;
                    res.insert(temp);
                }
            }
            left.insert(s[i]);
        }
        
        return res.size();
    }
};