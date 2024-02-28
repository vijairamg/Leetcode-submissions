/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
 
public:
    int findBottomLeftValue(TreeNode* root) {
        vector<vector<int>> levels;
        
        if(!root){
            return -1;
        }
        
        vector<TreeNode*> cur(1,root);
        
        while(cur.size() != 0){
            
            vector<int> vals;
            vector<TreeNode*> next;
            
            for(int i = 0; i < cur.size(); i++){                
                if(cur[i]->left){
                    next.push_back(cur[i]->left);
                }
                
                if(cur[i]->right){
                    next.push_back(cur[i]->right);
                }
                
                vals.push_back(cur[i]->val);
            }
            
            levels.push_back(vals);
            
            cur = next;
        }
    
        
        return levels[levels.size()-1][0];
    }
};