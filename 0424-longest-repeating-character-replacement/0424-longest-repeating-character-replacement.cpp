class Solution {
public:    
    int characterReplacement(string s, int k) {
        
        vector<int> count(26,0);
        
        int ans = 0;
        int l = 0;
        
        for(int r = 0; r < s.size(); r++){
            count[s[r]-'A']+=1;
            
            int max_freq = *max_element(count.begin(),count.end());
            
            while(max_freq+k < (r-l+1)){
                max_freq = *max_element(count.begin(),count.end());
                count[s[l]-'A']-=1;
                l+=1;
            }
            
            ans = max(ans,r-l+1);
            
        }
        
        return ans;
    }
};