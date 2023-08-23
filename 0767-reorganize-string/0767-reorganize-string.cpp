class Solution {
public:
    string reorganizeString(string s) {
        
        unordered_map<char,int> count;
        
        for(char c : s){
            count[c]+=1;
        }
        
        vector<pair<int,char>> heap;
        
        for(auto it = count.begin(); it != count.end(); it++){
            heap.push_back({it->second,it->first});
        }
        
        priority_queue<pair<int,char>> pq(heap.begin(),heap.end());
        
        auto prev = make_pair(-1,'*');
        string res = "";
        
        while(!pq.empty() || prev.first != -1){
            if(prev.first != -1 && pq.empty()){
                return "";
            }
            
            auto element = pq.top();
            pq.pop();
            int freq = --element.first;
            
            res += element.second;
           
            if(prev.first != -1){
                pq.push({prev.first,prev.second});
                prev = make_pair(-1,'*');
            }
            
            if(freq != 0){
                prev = make_pair(freq,element.second);
            }
        }
        
        return res;
    }
};