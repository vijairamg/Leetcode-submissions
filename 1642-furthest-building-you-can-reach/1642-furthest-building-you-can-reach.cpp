class Solution {
public:
  
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        priority_queue<int> pq;
        
        int rsum = bricks;
        
        for(int i = 1; i < heights.size(); i++){
            if(heights[i] <= heights[i-1])
                continue;
            
            pq.push(heights[i] - heights[i-1]);
            bricks -= (heights[i] - heights[i-1]);
                        
            if(bricks < 0){
                if(ladders > 0){
                    int add = pq.top();
                    pq.pop();
                
                    bricks += add;
                
                    ladders-=1;
                }else{
                    return i-1;
                }
            }
        }
        
        return heights.size()-1;
    }
};