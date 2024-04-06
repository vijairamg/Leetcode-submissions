class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        vector<int> toBeRemoved;
        
        stack<int> st;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(i);
            }else if(s[i] == ')'){
                if(st.empty()){
                    toBeRemoved.push_back(i);
                }else{
                    st.pop();
                }
            }
        }
                
        while(!st.empty()){
            toBeRemoved.push_back(st.top());
            st.pop();
        }
        
        sort(toBeRemoved.begin(),toBeRemoved.end());
        
        if(toBeRemoved.size() == 0){
            return s;
        }
        
        string n = "";
        int j = 0;
                
        for(int i = 0; i < s.size(); i++){
            if(j < toBeRemoved.size() && toBeRemoved[j] == i){
                j+=1;
                continue;
            }
            
            n += s[i];
        }
                
        return n;
    }
};