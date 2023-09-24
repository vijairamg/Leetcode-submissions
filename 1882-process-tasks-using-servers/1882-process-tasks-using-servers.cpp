class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        
        int n = servers.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> busy;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> free;
        
        vector<int> ans(tasks.size(),-1);
        
        for(int i = 0; i < servers.size(); i++){
            free.push({servers[i],i});
        }
        
        int i = 0;
        int t = 0;
        
        while(i < tasks.size()){
            
            // cout<<t<<endl;
            
            while(!busy.empty() && busy.top()[0] <= t){
                auto elem = busy.top();
                // cout<<elem[0]<<" "<<elem[1]<<" "<<elem[2]<<endl;
                free.push({elem[1],elem[2]});
                busy.pop();
            }
            
            while(!free.empty() && i < tasks.size() && i <= t){
                auto elem = free.top();
                free.pop();
                
                busy.push({t+tasks[i],elem[0],elem[1]});
                
                ans[i] = elem[1];
                i+=1;
            }
            
            if(free.empty()){
                t = max(t,busy.top()[0]);
            }else{
                t+=1;
            }
        }
        
        return ans;
    }
};