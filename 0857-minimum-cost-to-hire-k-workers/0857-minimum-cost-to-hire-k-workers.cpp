class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
        int n = quality.size();
        
        vector<int> pos(n);
        
        for(int i = 0; i < n; i++)
            pos[i] = i;
        
        sort(pos.begin(),pos.end(),[&](int a, int b){
            double a1 = wage[a];
            double b1 = wage[b];
            
            return a1/quality[a] < b1/quality[b];
        });
        
        // copy(pos.begin(),pos.end(),ostream_iterator<int>(cout," "));    

        priority_queue<int> pq;
        
        double rsum = 0;
    
        //pre
        for(int i = 0; i < k; i++){
            rsum += quality[pos[i]];
            pq.push(quality[pos[i]]);
        }

        double ans = (rsum*((double)wage[pos[k-1]]/quality[pos[k-1]]));
        
        
        for(int i = k; i < n; i++){            
            int m = pq.top();
            pq.pop();
            
            rsum -= m;
            rsum += quality[pos[i]];
            pq.push(quality[pos[i]]);
            
            ans = min(ans,rsum*((double)wage[pos[i]]/quality[pos[i]]));
            
        }
        
        return ans;
    }
};