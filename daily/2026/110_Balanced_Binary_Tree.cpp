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

TreeNode* createTree(vector<int>& nodes){
    if (nodes.empty()) return nullptr;
    int n = nodes.size();
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> que;
    que.push(root);
    int idx = 1;
    while(idx < n && !que.empty()){
        TreeNode* curr = que.front();
        que.pop();
        if (idx < n && nodes[idx] != -1){
            curr->left = new TreeNode(nodes[idx]);
            que.push(curr->left);
        }
        idx++;
        if (idx < n && nodes[idx] != -1){
            curr->right = new TreeNode(nodes[idx]);
            que.push(curr->right);
        }
        idx++;
    }
    return root;
}

class Solution {
public:
    bool ans = true;
    int dfs(TreeNode* root){
        if (root == nullptr) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        if (abs(l - r) > 1) ans = false;
        return max(l, r) + 1;
    }
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

int main(){
    vector<int> nodes = {3,9,20,-1,-1,15,7};
    // vector<int> nodes = {1,2,2,3,3,-1,-1,4,4};
    // vector<int> nodes = {};
    TreeNode* root = createTree(nodes);
    Solution S;
    cout << S.isBalanced(root) << endl;
    return 0;
}