class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        map<int,int> dp;
        
        for(int num : hand){
            dp[num]+=1;
        }
        
        for(auto it = dp.begin(); it!=dp.end(); it++){
            
            
            int start = it->first;
            int min = it->second;
           
            if(min == 0){
                continue;
            }
            
            for(int i = 0; i < groupSize; i++){
                if(dp.find(start+i) == dp.end()){
                    return false;
                }
                
                if (dp[start+i] < min){
                    return false;
                }else{
                    dp[start+i] -= min;
                }
            }
        }
        
        return true;
    }
};