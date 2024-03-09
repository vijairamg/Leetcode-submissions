class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        sort(tokens.begin(), tokens.end());
        
        int r = tokens.size()-1;
        
        int mscore = 0;
        int score = 0;
        
        for(int l = 0; l <= r; l++){
            if(power >= tokens[l]){
                power -= tokens[l];
                score+=1;
            }else if(score >= 1){
                score -=1;
                power += tokens[r];
                r -=1;
                l-=1;
            }
            mscore = max(score,mscore);
        }
        
        return mscore;
    }
};