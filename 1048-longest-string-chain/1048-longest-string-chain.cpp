class Solution {
public:
    
    bool static compare(string &s1,string &s2){
        return s1.size() < s2.size();
    }
 
    
    bool isPred(const string &a , const string &b){
        if(a.length() != b.length()-1){
            return false;
        }
        
        int i = 0 , j = 0;
        int d = 0;
        
        while(i < a.length() && j < b.length()){
            if(a[i] == b[j]){
                i+=1;
                j+=1;
                continue;
            }else{
                d+=1;
                j+=1;
            }
        }
        
        return i == a.length();
    }
    
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(),words.end(),compare);
        
        vector<int> dp(words.size(),1);
        
        for(int i = 1; i < words.size(); i++){
            for(int j = 0; j < i; j++){
                if(isPred(words[j],words[i])){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
        }
        
        return *max_element(dp.begin(),dp.end());
    }
};