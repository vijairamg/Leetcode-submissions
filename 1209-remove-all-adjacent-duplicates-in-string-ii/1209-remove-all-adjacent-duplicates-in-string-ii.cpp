class Solution {
public:
    string removeDuplicates(string str, int k) {
        stack<pair<char,int>> s;
        
        int n = str.size();
        
        for(int i = n-1; i >= 0; i--){
            if(s.empty()){
                s.push({str[i],1});
                continue;
            }
            
            auto ele = s.top();
            char c = ele.first;
            int t = ele.second;
            
            if(c == str[i]){
                s.pop();
                if(t+1 < k){
                    s.push({str[i],t+1});
                } 
            }else{
                s.push({str[i],1});
            }
        }
        
        string res;
        
        while(!s.empty()){
            auto ele = s.top();
            s.pop();
            
            char c = ele.first;
            int t = ele.second;
            
            for(int i = 0; i < t; i++){
                res += c;
            }
        }
        
        return res;
    }
};