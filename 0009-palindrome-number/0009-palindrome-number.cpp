class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x <= 0){
            return x == 0;
        }
        
        int ori = x;
        long long rev = 0;
        
        while(x){
            rev *= 10;
            rev += x%10;
            x/=10;
        }
        
        return ori == rev;
    }
};