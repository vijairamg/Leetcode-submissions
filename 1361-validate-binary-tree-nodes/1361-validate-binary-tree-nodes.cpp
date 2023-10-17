class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
     
        unordered_map<int,vector<int>> edges;
        
        vector<int> inDegree(n,0);
        
        for(int i = 0; i < n; i++){
            if(leftChild[i] != -1){
                edges[i].push_back(leftChild[i]);
                inDegree[leftChild[i]]+=1;
            }
            if(rightChild[i] != -1){
                edges[i].push_back(rightChild[i]);
                inDegree[rightChild[i]]+=1;
            }
        }
        
        int zeroCount = 0;
        int head = -1;
        
        for(int i = 0; i < n; i++){
            if(inDegree[i]==0){
                zeroCount+=1;
                head = i;
            }else if(inDegree[i] > 1){
                return false;
            }
        }
        
        if(zeroCount != 1)
            return false;
        
        queue<int> q;
        q.push(head);
        
        unordered_set<int> visited;
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            
            visited.insert(cur);
            
            for(int node : edges[cur]){
                if(visited.find(node) != visited.end())
                    return false;
                q.push(node);
            }
        }
        
        return visited.size() == n;
    }
};