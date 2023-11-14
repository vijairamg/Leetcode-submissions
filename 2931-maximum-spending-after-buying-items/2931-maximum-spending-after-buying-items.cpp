class Solution {
public:

    typedef pair<int, int> pi;
    using ll = long long;
    
    long long maxSpending(vector<vector<int>>& values) {
        
        int m = values.size();
        int n = values[0].size();
        
        priority_queue<pi, vector<pi>, greater<pi> > pq; 
        
        vector<int> cur(m,n-1);
        
        //init
        for(int i = 0; i < m; i++){
            pq.push(make_pair(values[i][n-1],i));
        }

        ll ans = 0;
        
        for(ll d = 1;d <= m*n; d++){
            
            const auto [val,shop] = pq.top();
            pq.pop();
            
            if(cur[shop] > 0){
                cur[shop]-=1;
                pq.push({values[shop][cur[shop]],shop});
            }
            
            ans+= d*val;
        }
        
        return ans;
    }
};