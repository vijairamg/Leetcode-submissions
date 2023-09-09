class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen;
        unordered_set<string> seen_twice;
        
        if(s.size() < 10){
            return {};
        }
        
        
        
        for(int i = 0; i < s.size()-9; i++){
            string cur = s.substr(i,10);
            if(seen.find(cur) != seen.end()){
                seen_twice.insert(cur);
            }else{
                seen.insert(cur);
            }
        }
        
        vector<string> res;
        res.insert(res.begin(),seen_twice.begin(),seen_twice.end());
        
        return res;
    }
};