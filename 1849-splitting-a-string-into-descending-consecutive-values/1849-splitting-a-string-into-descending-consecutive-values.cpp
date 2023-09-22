class Solution {
public:
    bool splitString(string s) {
        this->s = s;
        return split(0);
    }
    
private:
    
    string s;
    
    bool split(int pos,string cur = "",long long prev = -1){
        if(pos == s.size()){
            // cout<<"End"<<cur<<endl;
            return cur != "" && prev-stoll(cur) == 1;
        }
        
        cur = cur + s[pos];
        
        // cout<<cur<<endl;
        long long curValue = 0;
        try{
            curValue = stoll(cur);
        }catch(...){
            return false;
        }
        
        if(prev != -1 && curValue > prev){
            return false;
        }
        
        //split
        
        bool flag = false;

        if(curValue != 0){
            if(prev == -1 || prev-curValue == 1){
                flag = split(pos+1,"",curValue);
            }    
        }
        
        //dont split

        return flag || split(pos+1,cur,prev);
    }
    
};