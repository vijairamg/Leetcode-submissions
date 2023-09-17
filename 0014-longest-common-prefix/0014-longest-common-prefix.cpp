class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string common = strs[0];
        
        for(int i = 1; i < strs.size(); i++){
            int j = 0;
            
            while(j < min(strs[i].size(),common.size()) && common[j] == strs[i][j]){
                j+=1;
            }
            
            if(j == 0){
                return "";
            }
                    
            common = common.substr(0,j);
        }
        
        return common;
    }
};