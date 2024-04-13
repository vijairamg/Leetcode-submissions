class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        
        queue<int> q;
        
        for(int i = 0; i < deck.size(); i++){
            q.push(i);
        }
        
        int count = 0;
        vector<int> ans(deck.size(),0);
        
        while(count < deck.size()){
            
            int i1 = q.front();
            q.pop();
            
            if(q.size() > 0){
                int t = q.front();
                q.pop();
                q.push(t);
            }
            
            // cout<<count<<" "<<i1<<" "<<deck[i1]<<endl;
            ans[i1] = deck[count];
                
            count+=1;
        }
        
        return ans;
    }
};