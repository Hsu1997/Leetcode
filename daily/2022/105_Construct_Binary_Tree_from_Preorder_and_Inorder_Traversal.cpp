#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void levelOrder(TreeNode* root) {
    if (!root) return;
    vector<vector<int>> ans;
    queue<TreeNode*> que;
    que.push(root);
    queue<TreeNode*> next_level;
    while(!que.empty()){
        vector<int> now_level;
        while(!que.empty()){
            TreeNode* temp = que.front();
            que.pop();
            now_level.push_back(temp->val);
            if (temp->left) next_level.push(temp->left);
            if (temp->right) next_level.push(temp->right);
        }
        ans.push_back(now_level);
        swap(que, next_level);
    }
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
}

class Solution {
public:
    TreeNode* createsubtree(vector<int>& preorder, vector<int>& inorder, int pre_start, int in_start, int tree_limit){
        if (pre_start >= preorder.size() || in_start >= inorder.size()) return nullptr;

        int in_mid = in_start;
        while(inorder[in_mid] != preorder[pre_start]) in_mid++;

        TreeNode* root = new TreeNode(preorder[pre_start]);
        if (in_mid - in_start > 0) root->left = createsubtree(preorder, inorder, pre_start+1, in_start, in_mid);
        if (in_mid + 1 < tree_limit) root->right = createsubtree(preorder, inorder, pre_start + (in_mid - in_start) + 1, in_mid + 1, tree_limit);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = createsubtree(preorder, inorder, 0, 0, preorder.size());
        return root;
    }
};

int main(){
    // vector<int> preorder = {3,9,20,15,7};
    // vector<int> inorder = {9,3,15,20,7};
    vector<int> preorder = {3,1,2,4};
    vector<int> inorder = {1,2,3,4};
    Solution S;
    TreeNode* root = S.buildTree(preorder, inorder);
    levelOrder(root);
    return 0;
}