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

TreeNode* create_tree(vector<int> nodes){
    int n = nodes.size();
    if (n < 1) return nullptr;
    TreeNode* root = new TreeNode(nodes[0]);
    int i = 1;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        TreeNode* temp = que.front();
        que.pop();
        if (i < n && nodes[i] != -1){
            temp->left = new TreeNode(nodes[i]);
            que.push(temp->left);
        }
        i++;
        if (i < n && nodes[i] != -1){
            temp->right = new TreeNode(nodes[i]);
            que.push(temp->right);
        }
        i++;
    }
    return root;
}

class Solution {
public:
    int depth = 0;
    vector<vector<int>> ans = {};

    void dfs(TreeNode* node){
        if (!node) return;
        if (depth >= ans.size()) ans.push_back({node->val});
        else ans[depth].push_back(node->val);
        depth++;
        dfs(node->left);
        dfs(node->right);
        depth--;
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        dfs(root);
        for (int i = 1; i < ans.size(); i += 2){
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};

int main(){
    Solution S;
    vector<int> nodes = {3,9,20,-1,-1,15,7};
    // vector<int> nodes = {1};
    // vector<int> nodes = {};
    TreeNode* root = create_tree(nodes);
    vector<vector<int>> ans = S.zigzagLevelOrder(root);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}