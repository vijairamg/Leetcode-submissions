class Solution {
public:
    
    using pi = pair<int,int>;
    
    int minimumDeviation(vector<int>& nums) {
        
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        
        int max_heap = 0;
        
        for(int num : nums){
            
            int tmp = num;
            
            while(num % 2 == 0){
                num /= 2;
            }
            
            pq.push({num,max(tmp,2*num)});
            
            max_heap = max(max_heap,num);
            
        }
        
        int res = INT_MAX;
        
        while(pq.size() == nums.size()){
            
            auto [n,nMax] = pq.top();
            pq.pop();
                        
            res = min(res,max_heap-n);
            
            if(n < nMax){
                pq.push({2*n,nMax});
                max_heap = max(max_heap,n*2);
            }
        }
        
        return res;
    }
};