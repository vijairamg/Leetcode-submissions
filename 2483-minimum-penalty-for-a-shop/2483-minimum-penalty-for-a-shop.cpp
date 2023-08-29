class Solution {
public:
    int bestClosingTime(string customers) {
        
        int N = customers.size();
        
        vector<int> penY(N);
        vector<int> penN(N);
        
        int y = 0;
        int n = 0;
        
        for(int i = 0; i < N;i++){
            if(customers[i] == 'N'){
                n++;
            }
            penN[i] = n;
        }
        
        for(int i = N-1; i >= 0; i--){
            if(customers[i] == 'Y'){
                y++;
            }
            
            penY[i] = y;
        }
        
        for(int i = 1; i < N; i++){
            penY[i] += penN[i-1];
        }
        
        auto it = min_element(penY.begin(),penY.end());
        
        if(n < *it){
            return N;
        }
        
        return distance(penY.begin(),it);
    }
};