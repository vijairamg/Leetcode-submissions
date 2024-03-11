class Solution {
public:
    
    struct Node{
        Node* child[26];
        int count = 0;
    };
    
    void add(Node* head, string word){
        
        Node* ptr = head;
        
        for(int i = 0; i < word.size(); i++){
            
            int cur = word[i]-'a';
            
            if(ptr->child[cur] == nullptr){
                ptr->child[cur] = new Node();
            }
            
            ptr = ptr->child[cur];
            ptr->count+=1;
        }
        
    }
    
    void remove(Node* head, string word){
        
        Node* ptr = head;
        
        for(int i = 0; i < word.size(); i++){
            int cur = word[i]-'a';
            ptr = ptr->child[cur];
            ptr->count-=1;
        }
        
    }
    
    string check(Node* head, string s){
        Node* ptr = head;
        string ans = "";
        for(int i = 0; i < s.size(); ++i){
            int c = s[i] - 'a';
            if(ptr->child[c] == NULL) return ans;
            ans += s[i];
            ptr = ptr->child[c];
            if(ptr->count < 1) return ans;
        }
        return string(21,'s');
    }
    
    vector<string> shortestSubstrings(vector<string>& arr) {
        
        Node* head = new Node();
        
        for(string a : arr){
            for(int i = 0; i < a.size(); i++){
                for(int j = i; j < a.size(); j++){
                    // cout<<a.substr(i,j-i+1)<<endl;
                    add(head,a.substr(i,j-i+1));
                }
            }
        }
        
        vector<string> res;
            
        for(string a : arr){
            // cout<<endl;
            string s = a + a;
            
            for(int i = 0; i < a.size(); i++){
                for(int j = i; j < a.size(); j++){
                    // cout<<a.substr(i,j-i+1)<<endl;
                    remove(head,a.substr(i,j-i+1));
                }
            }
            // cout<<endl;
            for(int i = 0; i < a.size(); i++){
                for(int j = i; j < a.size(); j++){
                    string t = check(head,a.substr(i,j-i+1));
                    // cout<<a.substr(i,j-i+1)<<" "<<t<<endl;
                    if(t.size() < s.size() || (t.size() == s.size() && t < s)) s = t;
                }
            }
            
            res.push_back( s.size() <= a.size() ? s: "");
            
            for(int i = 0; i < a.size(); i++){
                for(int j = i; j < a.size(); j++){
                    add(head,a.substr(i,j-i+1));
                }
            }
            
        }
        
        return res;
    }
};