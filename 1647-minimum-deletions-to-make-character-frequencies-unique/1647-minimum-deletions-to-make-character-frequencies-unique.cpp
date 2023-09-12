class Solution {
public:
    int minDeletions(string s) {
        
        unordered_map<char,int> count;
        
        for(char c : s){
            count[c]+=1;
        }
        
        unordered_set<int> used_freq;
        int res = 0;
        
        for(auto it = count.begin(); it != count.end(); it++){
            
            int freq = it->second;
            
            while(freq > 0 && used_freq.find(freq) != used_freq.end()){
                freq--;
                res+=1;
            }
            
            used_freq.insert(freq);
        }
        
        return res;
    }
};