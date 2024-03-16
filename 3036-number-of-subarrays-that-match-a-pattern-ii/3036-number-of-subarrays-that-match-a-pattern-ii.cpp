class Solution {
public:
    
    vector<int> prefix(vector<int> s){
        
        vector<int> pi(s.size());
        
        for(int i = 1; i < s.size(); i++){
                        
            int j = pi[i-1];
            
            while(j > 0 && s[i] != s[j]){
                j = pi[j-1];
            }
            
            if(s[i] == s[j]){
                j+=1;
            }
            
            pi[i] = j;
        }
        
        return pi;
    }
    
    int find(const vector<int>&s, const vector<int> &p ,const vector<int>&pi){
        
        int cnt = 0;
        
        int i = 0, j = 0;
        while (i < s.size()) {
            if (j < p.size() && s[i] == p[j]) {
                i++;
                j++;
            } else {
                if (j == p.size()) {
                    cnt++;
                }
                if (j != 0) {
                    j = pi[j - 1];
                } else {
                    i++;
                }
            }
        }
        
        if (j == p.size()) {
            cnt++;
        }
        
        
        return cnt;
    }
    
    // typedef unsigned long long ll;
    
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        
        vector<int> pi = prefix(pattern);
        
        vector<int> s;
        
        for(int i = 1; i < nums.size(); i++){
            s.push_back((nums[i]-nums[i-1]>0) - (nums[i]-nums[i-1] < 0));
        }
                
        // copy(s.begin(),s.end(),ostream_iterator<int>(cout," "));
        // cout<<endl;
        
        return find(s,pattern,pi);
    }
};