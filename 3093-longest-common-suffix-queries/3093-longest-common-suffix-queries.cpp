class Solution {
public:
    
    struct Node{
        Node* child[26];
        int length;
        int index;
    };
    
    void add(Node* head, string word, int index){
        
        Node* ptr = head;
        
        for(int i = word.size()-1; i >= 0; i--){
            
            int cur = word[i]-'a';
            
            if(ptr->child[cur] == nullptr){
                ptr->child[cur] = new Node();
                ptr->child[cur]->length = word.size();
                ptr->child[cur]->index = index;
            }else{                
                if(word.size() < ptr->child[cur]->length){
                    ptr->child[cur]->length = word.size();
                    ptr->child[cur]->index = index;
                }
            }
                    
            ptr = ptr->child[cur];
        }
        
    }
    
    int check(Node* head, string s,vector<string>& wordsContainer){
        Node* ptr = head;
        
        int ansSoFar = -1;
        
        for(int i = s.size()-1; i >= 0; i--){
            int c = s[i] - 'a';
            if(ptr->child[c] == NULL) return ansSoFar;
            
            // cout<<s[i]<<endl;
            
            ptr = ptr->child[c];
        
            ansSoFar = ptr->index;
        }
        
        return ansSoFar;
    }
    
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        
        Node* head = new Node();
        
        int minV = INT_MAX;
        int minI = -1;
        
        for(int i = 0; i < wordsContainer.size(); i++){
            add(head,wordsContainer[i],i);
            
            if(wordsContainer[i].size() < minV){
                minV = wordsContainer[i].size();
                minI = i;
            }
        }
        
        vector<int> ans;
        
        
        for(int i = 0; i < wordsQuery.size(); i++){
                        
            int res = check(head,wordsQuery[i],wordsContainer);
            
            if(res == -1){
                ans.push_back(minI);
            }else{
                ans.push_back(res);
            }
            
        }
        
        return ans;
    }
};