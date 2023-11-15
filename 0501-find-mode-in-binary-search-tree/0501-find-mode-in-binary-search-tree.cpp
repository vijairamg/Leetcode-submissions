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
    vector<int> findMode(TreeNode* root) {
        
        TreeNode* cur = root;
        
        vector<int> values;
        
        int maxStreak = -1;
        int curStreak = -1;
        int cv = -1;
        vector<int> res;
        
        while(cur){
            if(cur->left){         
                TreeNode* neighbor = cur->left;
    
                while(neighbor->right){
                    neighbor = neighbor->right;
                }
              
               TreeNode* temp = cur->left;
               cur->left = nullptr;
               neighbor->right = cur;
               cur = temp;
                
            }else{

                if(cur->val != cv){
                    cv = cur->val;
                    curStreak = 1;
                }else{
                    curStreak+=1;
                }
                
                if(curStreak == maxStreak){
                    res.push_back(cur->val);
                }
                
                if(curStreak > maxStreak){
                    maxStreak = curStreak;
                    res.clear();
                    res.push_back(cur->val);
                }
                
                cur = cur->right;        
            }
        }
        
        return res;
    }
};