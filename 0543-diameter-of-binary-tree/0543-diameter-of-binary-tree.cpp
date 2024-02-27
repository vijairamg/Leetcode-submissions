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
    
    int m;
    
    int dfs(TreeNode* root){
        if(root != nullptr){
            
            int left = dfs(root->left);
            int right = dfs(root->right);
            
            // cout<<root->val<<" "<<1+left+right<<endl;
            
            m = max(m,1+left+right);
            
            return max(1+left,1+right);
        }
        
        return 0;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        dfs(root);
        
        return m-1;
    }
};