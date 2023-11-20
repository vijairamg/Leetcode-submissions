class Solution {
public:
    
    int solve(queue<pair<int,int>> &q,const vector<int> &tt){
        
        if(q.size() == 0)
            return 0;
        
//         if(q.size() == 1){
//             int [index,gc] = q.top();
//             g.pop();
            
//             return (tt[index]-tt[0])+gc;
//         }
        
        int start = 0;
        int ans = 0;
        
        while(!q.empty()){
            auto [index,gc] = q.front();
            q.pop();
            
            ans+= (tt[index]-tt[start])+gc;
                
            start = index;
        }
        
        return ans;
    }
    
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int G = garbage.size();
        vector<int> tt(G,0);
        
        for(int i = 0; i < travel.size(); i++){
            tt[i+1] = tt[i] + travel[i];
        }
        
        // copy(tt.begin(),tt.end(),ostream_iterator<int>(cout," "));

        queue<pair<int,int>> p,g,m;
        int i = 0;
        
        for(const string& garb : garbage){
            int pc = 0, gc = 0, mc = 0;
            
            for(char c : garb){
                if(c == 'P'){
                    pc+=1;
                }else if(c == 'G'){
                    gc+=1;
                }else{
                    mc+=1;
                }
            }
            
            if (pc != 0)
                p.push({i,pc});
            
            if (gc != 0)
                g.push({i,gc});
            
            if (mc != 0)
                m.push({i,mc});
            i+=1;
        }
        
        int ans = solve(p,tt);
        ans += solve(g,tt);
        ans += solve(m,tt);
        
        return ans;
    }
};