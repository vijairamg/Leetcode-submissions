class Solution {
public:
    
    void print(vector<int>& a){
        for(int i = 0; i < a.size(); i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        res.push_back({});
        this->nums = nums;
        
        vector<int> start;
        
        dfs(0,start);
        
        return res;
    }
    
private:
    vector<vector<int>> res;
    vector<int> nums;
    
    void dfs(int start,vector<int> &c){
        if(start == nums.size()){
            return;
        }
        
        for(int i = start; i < nums.size(); i++){
            c.push_back(nums[i]);
            vector<int> newC(c.begin(),c.end());
            res.push_back(newC);
            dfs(i+1,c);
            c.pop_back();
        }
    }
};