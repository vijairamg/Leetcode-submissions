class Solution {

unordered_map<string,vector<string>> times;
unordered_map<string,int> count;
    
    int getDiff(string a, string b){
        int ah = stoi(a.substr(0,2));
        int am = stoi(a.substr(2,4));
        
        // cout<<ah<<" "<<am<<endl;
        
        int bh = stoi(b.substr(0,2));
        int bm = stoi(b.substr(2,4));
    
        // cout<<bh<< " "<<bm<<endl;
        
        if(bh == ah)
            return bm-am;
        
        int da = am == 0 ? 0 : 60-am;
        int dh = am == 0 ? ah : ah+1;
        
        return da + (bh-dh)*60 + bm;
    }
    
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        
        sort(access_times.begin(),access_times.end());
        
        unordered_set<string> res;
        
        for(const auto& access : access_times){
            times[access[0]].push_back(access[1]);
        }
        
        for(const auto& [key,value] : times){
            
            if(value.size() < 3){
                continue;
            }
            
            for(int i = 0; i < value.size()-2; i++){
                
                // cout<<value[i]<<" "<<value[i+2]<<endl;
                
                if(getDiff(value[i],value[i+2]) < 60){
                    res.insert(key);
                    break;
                }
            }
        }
        
        return  vector(res.begin(),res.end());
    }
};