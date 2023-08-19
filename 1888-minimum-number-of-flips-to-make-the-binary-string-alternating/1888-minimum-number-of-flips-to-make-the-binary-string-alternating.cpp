class Solution {
public:
    int minFlips(string s) {
        
        int n = s.size();
        
        s = s + s;
        
        string alt1 = "";
        string alt2 = "";
        
        int prev1 = 0;
        int prev2 = 1;
        
        for(int i = 0; i < 2*n; i++){
            alt1 += to_string(prev1);
            alt2 += to_string(prev2);
            
            prev1 = !prev1;
            prev2 = !prev2;
        }
        
        int l = 0;
        int r = 0;
        
        int res = n;
        int d1 = 0;
        int d2 = 0;
        
        while(r < 2*n){
            d1 += s[r] != alt1[r];
            d2 += s[r] != alt2[r];
            
            if(r >= n - 1){
                res = min(res,min(d1,d2));
                d1 -= s[l] != alt1[l];
                d2 -= s[l] != alt2[l];
                l+=1;
            }
            
            r+=1;
        }
        
        return res;
    }
};