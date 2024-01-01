class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int j = 0;
        
        int count = 0;
        
        for(int i = 0; i < g.size() && j < s.size(); i++){
            
            while(j < s.size() && s[j] < g[i]){
                j++;
            }
            
            if(j == s.size()){
                return count; 
            }
            
            count+=1;
            j+=1;
        }
        
        return count;
    }
};