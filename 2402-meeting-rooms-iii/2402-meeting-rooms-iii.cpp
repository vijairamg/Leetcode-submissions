class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        vector<int> count(n,0);
            
        priority_queue<int,vector<int>,greater<int>> avail;
        priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>>> used;
        
        sort(meetings.begin(),meetings.end());
        
        for(int i = 0; i < n; i++){
            avail.push(i);
        }
        
        int t = 0;
        
        for(vector<int> &meet : meetings){
            
            if(used.size() > 0){
                while(used.size() > 0 && used.top().first <= meet[0]){
                    int room = used.top().second;
                    used.pop();
                    avail.push(room);
                }
            }
        
            if(avail.size() > 0){
                int room = avail.top();
                avail.pop();
                
                count[room]+=1;
                
                used.emplace(make_pair(meet[1],room));
            }else{                
                auto [endTime,room] = used.top();
                used.pop();
                // cout<<"end meeting "<<endTime<<" "<<room<<endl;
                                
                if(endTime > meet[0]){
                    endTime += meet[1] - meet[0];    
                }else{
                    endTime = meet[1];
                }
                
                count[room]+=1;
                
                // cout<<"new meeting "<<endTime<<" "<<room<<endl;
                
                used.emplace(make_pair(endTime,room));
            }
            
        }
        
//         for(int i = 0; i < cout.size(); i++){
//             cout<<count[i]<<" ";
//         }
//         cout<<endl;
        
        return max_element(count.begin(),count.end()) - count.begin();    
    }
};