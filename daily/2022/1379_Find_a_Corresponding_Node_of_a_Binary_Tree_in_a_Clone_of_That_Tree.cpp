/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* dfs(TreeNode* original, TreeNode* cloned, TreeNode* target){
        if (original == target) return cloned;
        if (original->left) {
            TreeNode* temp = dfs(original->left, cloned->left, target);
            if (temp) return temp;
        }
        if (original->right){
            TreeNode* temp = dfs(original->right, cloned->right, target);
            if (temp) return temp;
        }
        return nullptr;
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return dfs(original, cloned, target);
    }
};