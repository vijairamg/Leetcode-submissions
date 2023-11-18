class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        
        unordered_map<char,unordered_set<string>> dict;
        
        for(const string& idea : ideas){
            dict[idea[0]].insert(idea.substr(1));
        } 
        
        if(dict.size() < 2){
            return 0;
        }
        
       // for(const auto& [key,value] : count){
       //     cout<<key<<" "<<value<<endl;
       // }
       
        long long count = 0;
        
        for(int i = 0; i < 26; i++){
            
            char a = 'a' + i;
            
            if(dict.find(a) == dict.end())
                continue;
                        
            for(int j = i+1; j < 26; j++){
                char b = 'a' + j;
                
                if(dict.find(b) == dict.end())
                    continue;
                
                int aKeys = dict[a].size();
                int bKeys = dict[b].size();
                 
                for(const auto& suffix : dict[a]){
                    if(dict[b].find(suffix) != dict[b].end()){
                        aKeys--;
                        bKeys--;
                    }
                }
                
                count += 2 * (aKeys*bKeys);
                //cout<<a<<" "<<b<<" "<<count<<endl;    
            }
        }
        
        return count;
    }
};