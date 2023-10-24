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
    vector<int> largestValues(TreeNode* root) {
        
        dfs(root,0);
        return sol;
    }

private:
    vector<int> sol;
    
    void addValue(int value,int level){
        if(sol.size() <= level){
            sol.push_back(value);
        }else{
            sol[level] = max(sol[level],value);
        }
    }
    
    void dfs(TreeNode* root, int level){
        if(root){
            addValue(root->val,level);
            
            dfs(root->left,level+1);
            dfs(root->right,level+1);
        }
    }
};